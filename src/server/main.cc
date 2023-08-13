#include "chat_server.hpp"

int main()
{
    sockaddr_in local;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_family = AF_INET;
    local.sin_port = htons(8088);

    InetAddress inet_addr(local);
    EventLoop loop;

    ChatServer server(&loop, inet_addr, "chat_server");
    server.start();
    loop.loop();

    return 0;
}