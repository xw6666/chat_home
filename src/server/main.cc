#include "chat_server.hpp"
#include "chat_service.hpp"
#include <signal.h>

void handler(int signo)
{
    ChatService::getInstance()->reset();
    exit(0);
}

int main()
{

    signal(SIGINT, handler);
    // sockaddr_in local;
    // local.sin_addr.s_addr = INADDR_ANY;
    // local.sin_family = AF_INET;
    // local.sin_port = htons(8088);

    // InetAddress inet_addr(local);

    InetAddress inet_addr("127.0.0.1", 8080);
    EventLoop loop;

    ChatServer server(&loop, inet_addr, "chat_server");
    server.start();
    loop.loop();

    return 0;
}