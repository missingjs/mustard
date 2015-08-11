#include <cstddef>
#include <cstring>
#include "common/array.h"
using namespace mustard;

char * replace(const char * s, int i, int j, const char * t)
{
    if (!s) {
        return NULL;
    }

    int size = (int) strlen(s);
    if (i <= 0 || i > size || j <= 0 || !t) {
        char * s_clone = new char[size+1];
        strcpy(s_clone, s);
        return s_clone;
    }

    int new_size = 0;
    int tsize = (int) strlen(t);
    if (i + j - 1 <= size) {
        new_size = size - j + tsize;
    } else {
        new_size = i - 1 + tsize;
    }

    char * new_str = new char[new_size + 1];
    strncpy(new_str, s, i - 1);
    strncpy(new_str + i - 1, t, tsize);

    int m = i - 1 + tsize;
    for (int k = i + j - 1; k < size; ++k, ++m) {
        new_str[m] = s[k];
    }
    new_str[m] = 0;

    return new_str;
}
