# Makefile for socket examples

CXX=			g++ $(CCFLAGS)
ECHO-SERVER=		echo-server.o
ECHO-CLIENT=		echo-client.o
ECHO-SERVER-SLOW=	echo-server-slow.o
OBJS =			$(ECHO-SERVER) $(ECHO-CLIENT)

LIBS=

CCFLAGS= -g

all:	echo-server echo-client echo-server-slow

echo-server:$(ECHO-SERVER)
	$(CXX) -o echo-server $(ECHO-SERVER) $(LIBS)

echo-client:$(ECHO-CLIENT)
	$(CXX) -o echo-client $(ECHO-CLIENT) $(LIBS)

echo-server-slow:$(ECHO-SERVER-SLOW)
	$(CXX) -o echo-server-slow $(ECHO-SERVER-SLOW) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
	rm -f $(OBJS) $(OBJS:.o=.d) echo-server echo-client


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
