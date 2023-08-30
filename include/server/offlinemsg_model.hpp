#pragma once

#include <string>
#include <vector>

class OfflineMsgModel
{
public:
    // 保存用户的离线消息
    bool insert(int user_id, std::string msg);
    // 删除用户的离线消息
    bool remove(int user_id);
    // 查询用户的离线消息
    std::vector<std::string> query(int user_id);
};