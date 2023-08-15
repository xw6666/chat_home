#include "../../include/server/user_model.hpp"
#include "../../../include/server/db/db.hpp"
#include <string>

bool UserModel::insert(User &user)
{
    std::string sql;
    sql += "insert into User(name, password, state) values (";
    sql += user.getName().c_str() + ',';
    sql += user.getPasswd().c_str() + ',';
    sql += user.getState().c_str() + ')';

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
        user.setID(mysql_insert_id(mysql.getConn()));

        return true;
    }

    return false;
}