#include <stdlib.h>
#include <unistd.h>

#include <iostream>

#include "client.h"

using namespace std;

int
main(int argc, char **argv)
{
    int option;

    // setup default arguments
    int port = 3000;
    string host = "localhost";

    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"h:p:")) != -1) {
        switch (option) {
            case 'p':
                port = atoi(optarg);
                break;
            case 'h':
                host = optarg;
                break;
            default:
                cout << "client [-h host] [-p port]" << endl;
                exit(EXIT_FAILURE);
        }
    }

    Client client = Client(host, port);
    client.run();
}

