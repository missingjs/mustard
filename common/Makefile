SOURCES = xstring.cpp bitree.cpp id.cpp
OBJS = $(SOURCES:.cpp=.o)
CC = g++
CPPFLAGS = -std=c++11 -shared -fPIC

LIB_DIR = ../lib
LIB_NAME = libmustard.so
LIB_FILE = $(LIB_DIR)/$(LIB_NAME)
TARGET = $(LIB_FILE)

all: $(TARGET)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

sinclude $(SOURCES:.cpp=.d)

$(TARGET): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(LIB_FILE) $(OBJS)

clean:
	rm -f *.o *.d $(LIB_FILE)
