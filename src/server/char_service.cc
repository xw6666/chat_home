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
    if (name == "" || passwd == "")
    {
        result_value["errno"] = 1;
        std::string out_json = writer.write(result_value);
        conn->send(out_json);
        return;
    }

    UserModel user_model;
    User user;
    user.setName(name);
    user.setPasswd(passwd);
    bool status = user_model.insert(user);

    result_value["msg_id"] = REGIS_ACK;
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
