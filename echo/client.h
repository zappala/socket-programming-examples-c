#pragma once

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

class Client {
public:
  Client(std::string host, int port);
  ~Client();

  void run();

private:
  virtual void create();
  virtual void close_socket();
  void echo();
  bool send_request(std::string);
  bool get_response();

  std::string host_;
  int port_;
  int server_;
  int buflen_;
  char* buf_;
};
