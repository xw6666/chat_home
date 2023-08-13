#pragma once
#include <muduo/net/TcpServer.h>
#include <functional>
#include <jsoncpp/json/json.h>
#include <unordered_map>

using namespace muduo;
using namespace muduo::net;

using MsgHandler = std::function<void(const TcpConnectionPtr &, Json::Value &, Timestamp)>;

class ChatService
{
public:
    static ChatService *getInstance();

private:
    ChatService();
    // 负责处理登录的业务函数
    void login(const TcpConnectionPtr &conn, Json::Value &js_value, Timestamp time);
    // 负责处理注册的业务函数
    void region(const TcpConnectionPtr &conn, Json::Value &js_value, Timestamp time);

    // 通过id可以调用需要处理的业务函数
    std::unordered_map<int, MsgHandler> msg_handler_set;
};