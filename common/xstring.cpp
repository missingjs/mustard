#ifndef MUSTARD_XSTRING_H
#define MUSTARD_XSTRING_H 1

#include <iostream>
#include <cstring>
#include <string>

#include "xstring.h"

namespace mustard {

namespace xstring {

char * read(int & len);

char * read()
{
    int len = 0;
    return read(len);
}

char * read(int & len)
{
    if (!(std::cin >> len) || len < 0) {
        return NULL;
    }

    char * str = new char[len+1];
    str[len] = 0;

    for (int i = 0; i < len; ++i) {
        char c = 0;
        do {
            std::cin.get(c);
        } while (c == '\r' || c == '\n');
        str[i] = c;
    }

    return str;
}

char * read_line()
{
    std::string line;
    std::getline(std::cin, line);
    char * rs = new char[line.size() + 1];
    strcpy(rs, line.c_str());
    return rs;
}

void free(const char * str)
{
    delete[] str;
}

void print(const char * str)
{
    if (!str) {
        std::cout << "null string\n";
    } else {
        std::cout << '"' << str << "\"\n";
    }
}

char * clone(const char * str)
{
    if (!str) {
        return NULL;
    }

    size_t len = strlen(str);
    char * t = new char[len + 1];
    strcpy(t, str);
    return t;
}

} // namespace ::mustard::xstring

} // namespace ::mustard

#endif
