# Makefile for UNIX echo client and server

CXX=			g++ $(CCFLAGS)

UNIX-ECHO-SERVER=	unix-echo-server.o unix-server.o server.o
UNIX-ECHO-CLIENT=	unix-echo-client.o unix-client.o client.o
OBJS =			$(UNIX-ECHO-SERVER) $(UNIX-ECHO-CLIENT) 

LIBS=

CCFLAGS= -g

all:	unix-echo-server unix-echo-client

unix-echo-server:$(UNIX-ECHO-SERVER)
	$(CXX) -o server $(UNIX-ECHO-SERVER) $(LIBS)

unix-echo-client:$(UNIX-ECHO-CLIENT)
	$(CXX) -o client $(UNIX-ECHO-CLIENT) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
	rm -f $(OBJS) $(OBJS:.o=.d) server client


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
