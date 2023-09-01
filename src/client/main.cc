#include <functional>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <unordered_map>
using namespace std;

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <semaphore.h>
#include <atomic>

void Usage(const std::string &str)
{
    cerr << "Usage:\n\t" << str << " [ip] "
         << "[port] " << endl;
    exit(-1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        Usage(argv[0]);
    }

    return 0;
}