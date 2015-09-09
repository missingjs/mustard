SOURCES = mm.cpp
OBJS = $(SOURCES:.cpp=.o)
INCLUDE = -I. -I/home/venux021/workspace/mustard
LIBRARY = -L/home/venux021/workspace/mustard/common
CC = g++
CPPFLAGS = $(INCLUDE)

all: main

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

sinclude $(SOURCES:.cpp=.d)

main: $(OBJS)
	$(CC) -o main $(OBJS)

clean:
	rm -f *.o main *.d
