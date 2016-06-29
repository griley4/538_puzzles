CC = g++
LD = g++
CFLAGS = -O3 -Wall -std=c++11
LIBS = 

INCLUDE = -Iinclude -Idict
OBJS = $(patsubst src%.cc,lib%.o,$(wildcard src/*.cc))
EXECS = $(patsubst bin/%.cc,%,$(wildcard bin/*.cc))
EXEOBJS  = $(patsubst bin/%.cc,lib/%.o,$(wildcard bin/*.cc))


all: $(OBJS) $(EXEOBJS) $(EXECS)

lib/%.o : src/%.cc
				$(CC) -Wall $(CFLAGS) $(INCLUDE) -c $< -o $@

lib/%.o : bin/%.cc
				$(CC) -Wall $(CFLAGS) $(INCLUDE) -c $< -o $@

% : $(OBJS) lib/%.o
				$(LD) $(OBJS) lib/$@.o -o $@
clean:
				rm -f $(EXECS)  lib/*.o 
