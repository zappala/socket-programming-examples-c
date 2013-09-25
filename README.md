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

This code implements a more functional and complete echo server and
client. The client sends messages terminated by a newline, and the
server parses until it receives a newline. Both client and server
check the return value of send() and recv() and use loops to be sure
the entire message is sent or received in each case.

The main programs are in `echo-server.cc` and `echo-client.cc`. The
server uses `inet-server.cc` and `inet-server.h` to create Internet
sockets using IPv4 addresses. These files in turn rely on `server.cc`
and `server.h` for the protocol logic and processing. The client uses
`inet-client.cc` and `inet-client.h` to create the client version of
an Internet socket. These files likewise rely on `client.cc` and
`client.h` for the protocol processing.

## UNIX Echo Server and Client

This code converts the echo client and server to use UNIX sockets
instead of Internet sockets. UNIX sockets use the file system to identify
the socket, rather than IP addresses and ports. In this code, we use
`/tmp/unix-socket` as the name of the socket.

By using a UNIX socket, this code is restricted to communication with
local processes only. In addition, it is not portable to operating
systems that do not support UNIX sockets. This code is tested only on
Linux, but most of it should be portable to BSD and Mac OS X, with
some small changes.

The server uses `unix-echo-server.cc`, `unix-server.cc`, and
`unix-server.h`. These latter two files derive a class based on
`socket.cc` and `socket.h`. The client uses `unix-echo-client.cc`,
`unix-client.cc`, and `unix-client.h`. Likewise, these latter two
files derive a class based on `client.cc` and `client.h`.

Note that this code reuses the same base classes in `socket.h` and `client.h`,
showing how you can swap out a different type of socket, but the protocol
logic and processing remains the same.




