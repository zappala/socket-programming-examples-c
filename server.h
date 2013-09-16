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
    void handle(int port);
    string& get_request(int client);
    bool send_response(int client, const string& response);

    int port_;
    int server_;
    int buflen_;
    char* buf_;
};
