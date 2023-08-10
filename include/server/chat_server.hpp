#pragma once

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <functional>

using namespace muduo;
using namespace muduo::net;

class ChatServer
{
public:
    // 构造函数
    ChatServer(EventLoop *loop,
               const InetAddress &listenAddr,
               const string &nameArg );
    // 启动服务器
    void start();

private:

    // 处理连接事件的回调函数
    void onConnection(const TcpConnectionPtr &conn);
    // 处理事件到来的回调函数
    void onMessage(const TcpConnectionPtr &conn,
                   Buffer *message_string,
                   Timestamp time);

    TcpServer server_;
    EventLoop *loop_;
};