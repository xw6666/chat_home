#pragma once

#include <string>

class User
{
public:
    User(int id = -1, std::string name = "", std::string passwd = "", std::string state = "offline") : id_(id), name_(name), passwd_(passwd), state_(state) {}

    void setID(int id)
    {
        id_ = id;
    };
    void setName(const std::string &name) { name_ = name; }
    void setPasswd(const std::string &passwd) { passwd_ = passwd; }
    void setState(const std::string &state) { state_ = state; }

    int getID() const { return id_; }
    std::string getName() const { return name_; }
    std::string getPasswd() const { return passwd_; }
    std::string getState() const { return state_; }

protected:
    int id_;
    std::string name_;
    std::string passwd_;
    std::string state_;
};