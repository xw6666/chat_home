#pragma once

enum EnMsgType
{
    LOG_MSG = 1, // 登录消息id
    LOG_ACK,
    REGIS_MSG, // 注册消息
    REGIS_ACK, // 注册消息响应
    ONE_CHAT
};