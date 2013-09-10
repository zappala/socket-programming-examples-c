#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>

using namespace std;

int
main(int argc, char **argv)
{
    struct sockaddr_in server_addr;
    const char *ipaddress;
    int option, server, port;
    string line;
    char *buf;
    int buflen;

    // setup default arguments
    port = 3000;
    ipaddress = "127.0.0.1";

    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"s:p:")) != -1) {
        switch (option) {
            case 'p':
                port = atoi(optarg);
                break;
            case 's':
                ipaddress = optarg;
                break;
            default:
                cout << "client [-s IP address] [-p port]" << endl;
                exit(EXIT_FAILURE);
        }
    }

      // setup socket address structure
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (!inet_aton(ipaddress,&server_addr.sin_addr)) {
        printf("inet_addr() conversion error\n");
        exit(-1);
    }

      // create socket
    server = socket(PF_INET,SOCK_STREAM,0);
    if (server < 0) {
        perror("socket");
        exit(-1);
    }

      // connect to server
    if (connect(server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }

    // allocate buffer
    buflen = 1024;
    buf = new char[buflen+1];

    // read a line from standard input
    while (getline(cin,line)) {

        // write the data to the server
        send(server, line.c_str(), line.length(), 0);

        // read the response
        memset(buf,0,buflen);
        recv(server,buf,buflen,0);
        
        // print the response
        cout << buf << endl;
    }

    // Close socket
    close(server);
}

