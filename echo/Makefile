# Makefile for echo client and server

CXX=			g++ $(CXXFLAGS)

ECHO-SERVER=		echo-server.o server.o
ECHO-CLIENT=		echo-client.o client.o
OBJS =			$(ECHO-SERVER) $(ECHO-CLIENT)

LIBS=

CXXFLAGS= -g

all:	server client

server:$(ECHO-SERVER)
	$(CXX) -o server $(ECHO-SERVER) $(LIBS)

client:$(ECHO-CLIENT)
	$(CXX) -o client $(ECHO-CLIENT) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
	rm -f $(OBJS) $(OBJS:.o=.d) server client

%.o : %.cc
	$(CXX) -c -o $@ -MD -MP ${CPPFLAGS} ${CXXFLAGS} $<

-include $(OBJS:.o=.d)
