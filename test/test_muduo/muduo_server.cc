#include <functional>
#include <iostream>
#include <muduo/net/Buffer.h>
#include <muduo/net/Callbacks.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <string>

using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

/*基于muduo网络卡开发服务器程序
1.组合TcpServer对象
2.创建EventLoop事件循环对象的指针
3.明确TcpServer构造函数需要什么参数
4.在当前类的服务器中注册处理连接的回调函数和处理读写的回调函数
5.设置合适server线程数
 */
class ChatServer
{
public:
  ChatServer(EventLoop *loop, const InetAddress &listenAddr,
             const string &nameArg)
      : server_(loop, listenAddr, nameArg), loop_(loop)
  {
    // 给服务器注册用户连接的创建和断开回调
    server_.setConnectionCallback(
        std::bind(&ChatServer::onConnection, this, _1));
    // 给服务器注册用户读写事件回调
    server_.setMessageCallback(
        std::bind(&ChatServer::onMessage, this, _1, _2, _3));

    // 设置server线程数量
    server_.setThreadNum(4);
  }

  void start() { server_.start(); }

private:
  // 处理用户连接与断开
  void onConnection(const TcpConnectionPtr &conn)
  {
    if (conn->connected())
    {
      std::cout << conn->peerAddress().toIpPort() << "->"
                << conn->localAddress().toIpPort() << " state:online"
                << std::endl;
    }
    else
    {
      std::cout << conn->peerAddress().toIpPort() << "->"
                << conn->localAddress().toIpPort() << " state:offline"
                << std::endl;
    }
  }
  // 处理用户读写请求
  void onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp time)
  {
    string buf_string = buf->retrieveAllAsString();
    std::cout << "server recv:" << buf_string << " time:" << time.toString()
              << std::endl;
    conn->send("receive message success!");
  }

  TcpServer server_;
  EventLoop *loop_;
};

int main()
{
  EventLoop loop;

  // sockaddr_in local;
  // local.sin_addr.s_addr = INADDR_ANY;
  // local.sin_port = htons(8088);
  // local.sin_family = AF_INET;
  // InetAddress addr(local);
  InetAddress addr("127.0.0.1", 8088);
  ChatServer server(&loop, addr, "ChatServer");

  server.start();
  loop.loop(); // epoll_wait以阻塞的方式等待用户连接到来和读写事件到来

  return 0;
}
