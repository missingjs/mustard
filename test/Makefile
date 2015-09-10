SOURCES = mm.cpp
OBJS = $(SOURCES:.cpp=.o)
INCLUDE = -I. -I/home/qmtang/workspace/mustard
LIBRARY = -L/home/qmtang/workspace/mustard/lib -lmustard
CC = g++
CPPFLAGS = -g -std=c++11 $(INCLUDE)
TARGET = mm.out

all: $(TARGET)

%.d: %.cpp
	@set -e; rm -f $@; \
	$(CC) $(CPPFLAGS) -MM $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

sinclude $(SOURCES:.cpp=.d)

$(TARGET): $(OBJS)
	@cd /home/qmtang/workspace/mustard/common; \
	make; cd -; \
	$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY)

clean:
	rm -f *.o $(TARGET) *.d
