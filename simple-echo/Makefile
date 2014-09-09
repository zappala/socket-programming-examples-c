# Makefile for simple echo client and server

CXX=		g++ $(CCFLAGS)
SERVER=		server.o
CLIENT=		client.o
SLOW-SERVER=	slow-server.o
OBJS =		$(SERVER) $(CLIENT) $(SLOW-SERVER)

LIBS=

CCFLAGS= -g

all:	server client slow-server

server: $(SERVER)
	$(CXX) -o server $(SERVER) $(LIBS)

client: $(CLIENT)
	$(CXX) -o client $(CLIENT) $(LIBS)

slow-server: $(SLOW-SERVER)
	$(CXX) -o slow-server $(SLOW-SERVER) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
	rm -f $(OBJS) $(OBJS:.o=.d) server client slow-server


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
