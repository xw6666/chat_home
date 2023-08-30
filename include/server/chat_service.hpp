#pragma once

#include "./user_model.hpp"
#include <muduo/net/TcpServer.h>
#include <functional>
#include <jsoncpp/json/json.h>
#include <unordered_map>
#include <mutex>

using namespace muduo;
using namespace muduo::net;

using MsgHandler = std::function<void(const TcpConnectionPtr &, Json::Value &, Timestamp)>;
using Msgid = int;

class ChatService
{
public:
    static ChatService *getInstance();
    MsgHandler getHandler(Msgid msg_id);

    // 处理客户端退出时的函数
    void clientClose(const TcpConnectionPtr &conn);
    // 处理服务器退出时的状态设置
    void reset();

private:
    ChatService();
    // 负责处理登录的业务函数
    void login(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time);
    // 负责处理注册的业务函数
    void regis(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time);
    // 负责处理点对点聊天的业务函数
    void oneChat(const TcpConnectionPtr &conn, Json::Value &message_value, Timestamp time);
    // 通过id可以调用需要处理的业务函数
    std::unordered_map<Msgid, MsgHandler> msg_handler_set_;

    // 通过user id找到对应的连接
    std::unordered_map<int, TcpConnectionPtr> user_conn_set_;

    // 通过此类查询User数据库表
    UserModel user_model_;

    std::mutex conn_mutex_;

    // 单例指针
    static ChatService *ins_;
};