# Socket programming examples in C++

Simple examples that show how to do socket programming in C++. Use

> make

to compile all the code using the supplied `Makefile`.

## Echo Server and Client

The files `echo-server.cc` and `echo-client.cc` contain a basic echo
server and client. The server handles only one client at a time and
simply sends back to the client whatever it receives.

**Caution**: both the client and the server do not properly check the
return values of send() and recv(). This means that long messages may
not be echoed properly. Better code is in subsequent examples. This code
is here just to show the basics.




