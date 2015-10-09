import sys
import os

BASE_PATH = os.path.dirname(os.path.realpath(sys.argv[0]))
BASE_PATH = os.path.dirname(BASE_PATH)

makefile_content = \
'''SOURCES = {__case__}.cpp {__case__}.test.cpp
OBJS = $(SOURCES:.cpp=.o)
INCLUDE = -I. -I{__base_path__}
LIBRARY = -L. -l_base_ -L{__base_path__}/lib -lmustard 
CC = g++
CPPFLAGS = -g -std=c++11 $(INCLUDE)
TARGET = {__case__}.out
BASE_SRC = _base_.cpp
BASE_LIB = lib_base_.so

all: $(TARGET)

%.d: %.cpp
\t@set -e; rm -f $@; \\
\t$(CC) $(CPPFLAGS) -MM $< > $@.$$$$; \\
\tsed 's,\($*\)\.o[ :]*,\\1.o $@ : ,g' < $@.$$$$ > $@; \\
\trm -f $@.$$$$

sinclude $(SOURCES:.cpp=.d)

COMMON_LIB:
\t@cd {__base_path__}/common; \\
\tmake; cd -;

$(BASE_LIB): $(BASE_SRC) COMMON_LIB
\t$(CC) $(CPPFLAGS) -shared -fPIC -o $@ $(BASE_SRC)

$(TARGET): $(OBJS) $(BASE_LIB)
\t$(CC) $(CPPFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY)

clean:
\trm -f *.o $(TARGET) *.d
'''

def get_make_content(case_name):
    dic = {}
    dic['__case__'] = case_name
    dic['__base_path__'] = BASE_PATH
    return makefile_content.format(**dic)
