#pragma once

#include "user.hpp"

class UserModel
{
public:
    // 往数据库表插入一个用户，不传const，因为要顺便填入id
    bool insert(User &user);
    // 通过id像User表查询用户，将对应字段填入传出型参数user
    void query(int id, User *user);
    // 将user中的state更新到user数据库表中
    bool updateState(const User &user);
};