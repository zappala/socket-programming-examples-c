#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>

using namespace std;

class Server {
public:
    Server(int);
    ~Server();

private:

    void create();
    void serve();
    void handle(int);
    string get_request(int);
    bool send_response(int, string);

    int port_;
    int server_;
    int buflen_;
    char* buf_;
};
