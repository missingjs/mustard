#ifndef MUSTARD_XSTRING_H
#define MUSTARD_XSTRING_H 1

#include <iostream>

namespace mustard {

namespace xstring {

char * read(int & len)
{
    if (!(std::cin >> len) || len < 0) {
        return NULL;
    }

    char * str = new char[len+1];
    str[len] = 0;

    for (int i = 0; i < len; ++i) {
        std::cin >> str[i];
    }

    return str;
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

} // namespace ::mustard::xstring

} // namespace ::mustard

#endif
