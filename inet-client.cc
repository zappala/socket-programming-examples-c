#include "inet-client.h"

InetClient::InetClient(string host, int port) {
    host_ = host;
    port_ = port;
}

InetClient::~InetClient() {
}


void
InetClient::create() {
    struct sockaddr_in server_addr;

    // use DNS to get IP address
    struct hostent *hostEntry;
    hostEntry = gethostbyname(host_.c_str());
    if (!hostEntry) {
        cout << "No such host name: " << host_ << endl;
        exit(-1);
    }

    // setup socket address structure
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_);
    memcpy(&server_addr.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

    // create socket
    server_ = socket(PF_INET,SOCK_STREAM,0);
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
InetClient::close_socket() {
    close(server_);
}
