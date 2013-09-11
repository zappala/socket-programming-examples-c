# Socket programming examples in C++

Simple examples that show how to do socket programming in C++. Use

> make

to compile all the code using the supplied `Makefile`.

## Simple Echo Server and Client

The files `echo-server-simple.cc` and `echo-client-simple.cc` contain
a basic echo server and client. The server handles only one client at
a time and simply sends back to the client whatever it receives.

Run `echo-server-simple` with `echo-client-simple` and see what
happens.

**Caution**: both the client and the server do not properly check the
return values of send() and recv(). This means that long messages may
not be echoed properly. Better code is in subsequent examples. This code
is here just to show the basics.

## Slow Echo Server

To illustrate the poor quality of the code in the simple echo server
and client, the file `echo-server-slow.cc` is an echo server that
sends replies only one character at a time. While this is not how any
server is written, it illustrates what can happen when sending larger
messages across the network. Those messages can be split into smaller
pieces by TCP, so the a developer cannot assume that a single call to
recv() will get the entire message.

Run `echo-server-slow` with `echo-client-simple` and see what happens.

## Echo Server and Client

A more functional and complete echo server and client. The client
sends messages terminated by a newline, and the server parses until it
receives a newline. Both client and server check the return value of
send() and recv() and use loops to be sure the entire message is
sent or received in each case.

The main programs are in `echo-server.cc` and `echo-client.cc`. The
bulk of the server code is in `server.cc` and `server.h`. The bulk of
the client code is in `client.cc` and `client.h`.