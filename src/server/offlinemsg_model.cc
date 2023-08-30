#include "../../include/server/offlinemsg_model.hpp"
#include "../../../include/server/db/db.hpp"

bool OfflineMsgModel::insert(int user_id, std::string msg)
{
    char sql[1024] = {0};

    sprintf(sql, "insert into offlinemessage(userid, message) values (%d, '%s\')", user_id, msg.c_str());
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

bool OfflineMsgModel::remove(int user_id)
{
    char sql[1024] = {0};
    sprintf(sql, "delete from offlinemessage where userid = %d;", user_id);

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

std::vector<std::string> OfflineMsgModel::query(int user_id)
{
    char sql[1024] = {0};
    sprintf(sql, "select * from offlinemessage where userid = %d;", user_id);
    std::vector<std::string> msg_set;

    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res)
        {

            MYSQL_ROW row = nullptr;
            while (row = mysql_fetch_row(res))
            {
                std::string msg = row[1];
                msg_set.push_back(msg);
            }
            this->remove(user_id);
            mysql_free_result(res);
        }
    }
    return msg_set;
}
