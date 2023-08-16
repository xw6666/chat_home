#include "../../include/server/char_service.hpp"
#include "../../include/public.hpp"
#include "../../include/server/user_model.hpp"
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

void ChatService::login(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
{
    LOG_INFO << "do login service.";
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
                // 修改状态成功
                result_value["id"] = id;
                result_value["name"] = user.getName();
                result_value["errno"] = 0;
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

void ChatService::regis(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time)
{
    LOG_INFO << "do regis service.";
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

ChatService *ChatService::ins_ = nullptr;
