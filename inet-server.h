#pragma once

#include <netinet/in.h>

#include "server.h"

class InetServer : public Server {

public:
    InetServer(int);
    ~InetServer();

protected:
    void create();
    void close_socket();

private:
    int port_;
};
