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

void UserModel::query(int id, User *user)
{
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d;", id);

    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row)
            {
                user->setID(id);
                user->setName(row[1]);
                user->setPasswd(row[2]);
                user->setState(row[3]);
            }
            mysql_free_result(res);
        }
    }
}

bool UserModel::updateState(const User &user)
{
    char sql[1024] = {0};
    sprintf(sql, "update user set state = '%s' where id = %d;", user.getState().c_str(), user.getID());

    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
        return false;
    }

    return false;
}

bool UserModel::resetState()
{
    char sql[1024] = {0};
    sprintf(sql, "update user set state = \'offline\' where state = \'online\'");

    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
        return false;
    }

    return false;
}