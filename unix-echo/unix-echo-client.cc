#include "unix-client.h"

int
main(int argc, char **argv)
{
    UnixClient client = UnixClient();
    client.run();
}

