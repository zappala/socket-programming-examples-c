#pragma once

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <string>

class Client {
public:
  Client();
  ~Client();

  void run();

protected:
  virtual void create();
  virtual void close_socket();
  void echo();
  bool send_request(std::string);
  bool get_response();

  int server_;
  int buflen_;
  char* buf_;
};
