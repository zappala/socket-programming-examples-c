# Socket programming examples in C++

Simple examples that show how to do socket programming in C++. Use

> make

to compile all the code using the supplied `Makefile`.

## Echo Server and Client

The files `echo-server.cc` and `echo-client.cc` contain a basic echo
server and client. The server handles only one client at a time and
simply sends back to the client whatever it receives.

Run `echo-server` with `echo-client` and see what happens.

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

Run `echo-server-simple` with `echo-client` and see what happens.


