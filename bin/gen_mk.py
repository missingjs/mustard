import sys
import os

BASE_PATH = os.path.dirname(os.path.realpath(sys.argv[0]))
BASE_PATH = os.path.dirname(BASE_PATH)

makefile_content = \
'''SOURCES = {__case__}.cpp
OBJS = $(SOURCES:.cpp=.o)
INCLUDE = -I. -I{__base_path__}
LIBRARY = -L{__base_path__}/lib -lmustard
CC = g++
CPPFLAGS = -g -std=c++11 $(INCLUDE)
TARGET = {__case__}.out

all: $(TARGET)

%.d: %.cpp
\t@set -e; rm -f $@; \\
\t$(CC) $(CPPFLAGS) -MM $< > $@.$$$$; \\
\tsed 's,\($*\)\.o[ :]*,\\1.o $@ : ,g' < $@.$$$$ > $@; \\
\trm -f $@.$$$$

sinclude $(SOURCES:.cpp=.d)

$(TARGET): $(OBJS)
\t@cd {__base_path__}/common; \\
\tmake; cd -; \\
\t$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY)

clean:
\trm -f *.o $(TARGET) *.d
'''

if __name__ == '__main__':
    dic = {}
    dic['__case__'] = 'mm'
    dic['__base_path__'] = BASE_PATH
    with open('Makefile2', 'w') as f:    
        f.write(makefile_content.format(**dic))
