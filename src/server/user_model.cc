#include "../../include/server/user_model.hpp"
#include "../../../include/server/db/db.hpp"
#include <string>
#include <iostream>

bool UserModel::insert(User &user)
{
    std::string sql;
    sql += "insert into user(name, password, state) values (";
    sql += "\"" + user.getName() + "\", \"";
    sql += user.getPasswd() + "\", \"";
    sql += user.getState() + "\")";

    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            user.setID(mysql_insert_id(mysql.getConn()));
            return true;
        }
        return false;
    }

    return false;
}