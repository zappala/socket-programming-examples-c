#include "unix-server.h"

int main(int, char**) {
  UnixServer server = UnixServer();
  server.run();
}
