#include "unix-client.h"

UnixClient::UnixClient() {
    socket_name_ = "/tmp/unix-socket";
}

UnixClient::~UnixClient() {
}

void
UnixClient::create() {
    struct sockaddr_un server_addr;

    // setup socket address structure
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path,socket_name_,sizeof(server_addr.sun_path) - 1);

    // create socket
    server_ = socket(PF_UNIX,SOCK_STREAM,0);
    if (!server_) {
        perror("socket");
        exit(-1);
    }

    // connect to server
    if (connect(server_,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
}

void
UnixClient::close_socket() {
}
