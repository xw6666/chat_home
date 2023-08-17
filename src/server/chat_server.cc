#include "../../include/server/chat_server.hpp"
#include "../../include/server/chat_service.hpp"
#include "../../include/public.hpp"
#include <iostream>
#include <functional>
#include <string>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace placeholders;

ChatServer::ChatServer(EventLoop *loop,
                       const InetAddress &listenAddr,
                       const string &nameArg)
    : server_(loop, listenAddr, nameArg), loop_(loop)
{
    server_.setMessageCallback(bind(&ChatServer::onMessage, this, _1, _2, _3));
    server_.setConnectionCallback(bind(&ChatServer::onConnection, this, _1));

    server_.setThreadNum(4);
}

void ChatServer::start() { server_.start(); }

void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        // 处理客户端退出
        ChatService::getInstance()->clientClose(conn);
        conn->shutdown();
    }
}

void ChatServer::onMessage(const TcpConnectionPtr &conn,
                           Buffer *message_string,
                           Timestamp time)
{
    std::string message = message_string->retrieveAllAsString();
    Json::Reader reader;
    Json::Value message_value;
    reader.parse(message, message_value);
    Msgid msg_id = message_value["msg_id"].asInt();
    ChatService *server_ins = ChatService::getInstance();
    auto msg_handler = server_ins->getHandler(msg_id);
    msg_handler(conn, message_value, time);
}
