#pragma once

enum EnMsgType
{
    LOG_MSG = 1, // 登录消息id
    LOG_ACK = 2,
    REGIS_MSG = 3,   // 注册消息
    REGIS_ACK = 4,   // 注册消息响应
    ONE_CHAT_MSG = 5 // 点对点聊天消息
};