#include "../../include/server/chat_service.hpp"
#include "../../include/public.hpp"
#include "../../include/server/user_model.hpp"
#include "../../include/server/offlinemsg_model.hpp"
#include <functional>
#include <muduo/base/Logging.h>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace placeholders;
using namespace muduo;

ChatService *ChatService::getInstance()
{
    static std::mutex mutex_;
    if (nullptr == ins_)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (nullptr == ins_)
        {
            ins_ = new ChatService();
        }
    }

    return ins_;
}

ChatService::ChatService()
{
    // 注册函数
    msg_handler_set_.insert({LOG_MSG, std::bind(&ChatService::login, this, _1, _2, _3)});
    msg_handler_set_.insert({REGIS_MSG, std::bind(&ChatService::regis, this, _1, _2, _3)});
    msg_handler_set_.insert({ONE_CHAT_MSG, std::bind(&ChatService::oneChat, this, _1, _2, _3)});
}

MsgHandler ChatService::getHandler(Msgid msg_id)
{
    auto handler = msg_handler_set_.find(msg_id);
    if (handler == msg_handler_set_.end())
    {
        return [=](const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
        {
            LOG_ERROR << "msg_id:" << msg_id << "Failed to find matching callback function.";
        };
    }

    return msg_handler_set_[msg_id];
}

/*
mas_id:1
id:用户登录使用的id
passwd:用户登录的密码
*/
void ChatService::login(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
{
    LOG_INFO << "do login service.";
    try
    {
        int id = message_value["id"].asInt();
        std::string passwd = message_value["passwd"].asString();
        LOG_INFO << "id:" << id << " "
                 << "passwd:" << passwd;

        Json::Value result_value; // 传给客户端的json value
        Json::FastWriter writer;
        result_value["msg_id"] = LOG_ACK;
        User user;
        user_model_.query(id, &user);
        if (user.getID() == -1)
        {
            // 查询失败
            result_value["errno"] = 2;
        }
        else if (user.getID() == id && user.getPasswd() == passwd)
        {
            // 用户账号密码正确但是已经在线
            if (user.getState() == "online")
            {
                result_value["errno"] = 2;
            }
            else
            {
                // 登录成功，将状态改为online
                user.setState("online");
                if (user_model_.updateState(user))
                {

                    // 成功登录，将连接加入集合中(多线程场景)
                    {
                        std::lock_guard<std::mutex> lock(conn_mutex_);
                        user_conn_set_.insert({id, conn});
                    }
                    LOG_INFO << "add id:" << id << " to user_conn_set_";

                    // 修改状态成功
                    result_value["id"] = id;
                    result_value["name"] = user.getName();
                    result_value["errno"] = 0;

                    OfflineMsgModel offlinemsgmodel;
                    vector<string> offline_msg_set = offlinemsgmodel.query(id);
                    if (!offline_msg_set.empty())
                    {
                        for (auto &e : offline_msg_set)
                        {
                            result_value["offlinemsg"].append(e);
                        }
                    }
                }
                else
                {
                    // 内部错误
                    result_value["errno"] = 3;
                }
            }
        }
        else
        {
            // 用户名或密码错误
            result_value["errno"] = 2;
        }

        std::string out_json = writer.write(result_value);
        conn->send(out_json);
    }
    catch (const Json::Exception &e)
    {
        // 捕获 Json::Exception 异常，这表示 JSON 解析或转换错误
        LOG_ERROR << "JSON Exception caught: " << e.what();
    }
    catch (const std::exception &e)
    {
        // 捕获其他标准异常
        LOG_ERROR << "Standard Exception caught: " << e.what();
    }
}

/*
msg_id:3
name:用户注册的名称
passwd:用户密码
如果注册成功，返回数据库生成的id
*/
void ChatService::regis(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
{
    LOG_INFO << "do regis service.";

    try
    {
        std::string name = message_value["name"].asString();
        std::string passwd = message_value["passwd"].asString();
        LOG_INFO << "name:" << name << " "
                 << "passwd:" << passwd;
        Json::Value result_value; // 传给客户端的json value
        Json::FastWriter writer;
        result_value["msg_id"] = REGIS_ACK;
        if (name == "" || passwd == "")
        {
            result_value["errno"] = 1;
            std::string out_json = writer.write(result_value);
            conn->send(out_json);
            return;
        }

        User user;
        user.setName(name);
        user.setPasswd(passwd); // UserModel user_model;
        bool status = user_model_.insert(user);

        if (status)
        {
            result_value["errno"] = 0;
            result_value["id"] = user.getID();
        }
        else
        {
            result_value["errno"] = 1;
        }

        std::string out_json = writer.write(result_value);
        conn->send(out_json);
    }
    catch (const Json::Exception &e)
    {
        // 捕获 Json::Exception 异常，这表示 JSON 解析或转换错误
        LOG_ERROR << "JSON Exception caught: " << e.what();
    }
    catch (const std::exception &e)
    {
        // 捕获其他标准异常
        LOG_ERROR << "Standard Exception caught: " << e.what();
    }
}

void ChatService::clientClose(const TcpConnectionPtr &conn)
{
    User user;
    {
        std::lock_guard<std::mutex> lock(conn_mutex_);
        for (auto it = user_conn_set_.begin(); it != user_conn_set_.end(); ++it)
        {
            if (it->second == conn)
            {
                user_conn_set_.erase(it);
                user.setID(it->first);
                break;
            }
        }
    }
    if (user.getID() != -1)
    {
        user_model_.updateState(user);
    }
}

/*
msgid:5
to:收信息的id
from:发信息的用户名
id:发信息的id
msg:发的消息
*/
void ChatService::oneChat(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
{
    LOG_INFO << "do oneChat service.";
    int to_id = message_value["to"].asInt();
    // 先查数据库看用户是否存在
    User user;
    user_model_.query(to_id, &user);

    if (user.getID() == to_id)
    {
        // 用户存在
        {
            std::lock_guard<std::mutex> lock(conn_mutex_);
            auto iter = user_conn_set_.find(to_id);
            if (iter != user_conn_set_.end())
            {
                // 用户在线
                Json::FastWriter writer;
                std::string out_json = writer.write(message_value);

                iter->second->send(out_json);
            }
        }

        // 用户不在线 - 将消息放入数据库中
        Json::FastWriter writer;
        std::string out_json = writer.write(message_value);
        OfflineMsgModel offlinemodel;
        bool res = offlinemodel.insert(to_id, out_json);
        if (res)
            LOG_INFO << message_value["from"].asString() << " to " << to_id << "\'s offlinemessage save success.";
        else
        {
            LOG_ERROR << message_value["from"].asString() << " to " << to_id << "\'s offlinemessage save failed.";
        }
    }
    else
    {
        // 用户不存在
        // Json::Value result_value; // 传给客户端的json value
        // Json::FastWriter writer;
    }
}

ChatService *ChatService::ins_ = nullptr;
