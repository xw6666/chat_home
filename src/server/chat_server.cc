#include "../../include/server/chat_server.hpp"
#include <iostream>
#include <functional>

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
    if (conn->connected())
    {
        std::cout << "connected from " << conn->getTcpInfoString();
    }
}

void ChatServer::onMessage(const TcpConnectionPtr &conn,
                           Buffer *message_string,
                           Timestamp time)
{
    std::string str = message_string->retrieveAllAsString();

    std::cout << "server receive:" << str << std::endl;

    conn->send(str);
}
