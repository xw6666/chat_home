#include "../../include/server/char_service.hpp"
#include "../../include/public.hpp"
#include <functional>
#include <muduo/base/Logging.h>

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
}

ChatService *ChatService::ins_ = nullptr;
