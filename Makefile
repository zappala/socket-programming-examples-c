# Makefile for socket examples

CXX=			g++ $(CCFLAGS)
ECHO-SERVER-SIMPLE=	echo-server-simple.o
ECHO-CLIENT-SIMPLE=	echo-client-simple.o
ECHO-SERVER-SLOW=	echo-server-slow.o
ECHO-SERVER=		echo-server.o inet-server.o server.o
ECHO-CLIENT=		echo-client.o inet-client.o client.o
UNIX-ECHO-SERVER=	unix-echo-server.o unix-server.o server.o
UNIX-ECHO-CLIENT=	unix-echo-client.o unix-client.o client.o
OBJS =			$(ECHO-SERVER-SIMPLE) $(ECHO-CLIENT-SIMPLE) $(ECHO-SERVER-SLOW) $(ECHO-SERVER) $(ECHO-CLIENT) $(UNIX-ECHO-SERVER) $(UNIX-ECHO-CLIENT) 

LIBS=

CCFLAGS= -g

all:	echo-server-simple echo-client-simple echo-server-slow echo-server echo-client unix-echo-server unix-echo-client

echo-server-simple:$(ECHO-SERVER-SIMPLE)
	$(CXX) -o echo-server-simple $(ECHO-SERVER-SIMPLE) $(LIBS)

echo-client-simple:$(ECHO-CLIENT-SIMPLE)
	$(CXX) -o echo-client-simple $(ECHO-CLIENT-SIMPLE) $(LIBS)

echo-server-slow:$(ECHO-SERVER-SLOW)
	$(CXX) -o echo-server-slow $(ECHO-SERVER-SLOW) $(LIBS)

echo-server:$(ECHO-SERVER)
	$(CXX) -o echo-server $(ECHO-SERVER) $(LIBS)

echo-client:$(ECHO-CLIENT)
	$(CXX) -o echo-client $(ECHO-CLIENT) $(LIBS)

unix-echo-server:$(UNIX-ECHO-SERVER)
	$(CXX) -o unix-echo-server $(UNIX-ECHO-SERVER) $(LIBS)

unix-echo-client:$(UNIX-ECHO-CLIENT)
	$(CXX) -o unix-echo-client $(UNIX-ECHO-CLIENT) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
	rm -f $(OBJS) $(OBJS:.o=.d) echo-server-simple echo-client-simple echo-server-slow echo-server echo-client unix-echo-server unix-echo-client


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
