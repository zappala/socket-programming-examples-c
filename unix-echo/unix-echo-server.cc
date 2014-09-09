#include "unix-server.h"

int
main(int argc, char **argv)
{
    UnixServer server = UnixServer();
    server.run();
}
