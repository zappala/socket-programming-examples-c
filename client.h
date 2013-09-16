#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Client {
public:
    Client(const string& host, int port);
    ~Client();

private:

    void create();
    void echo();
    bool send_request(const string& request);
    bool get_response();

    int port_;
    string host_;
    int server_;
    int buflen_;
    char* buf_;
};
