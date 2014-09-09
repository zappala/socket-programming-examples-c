#pragma once

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/un.h>

#include "server.h"

class UnixServer : public Server {

public:
    UnixServer();
    ~UnixServer();

protected:
    void create();
    void close_socket();

private:
    static void interrupt(int);
    
    static const char* socket_name_;
};
