#include <cstddef>
#include <cstring>
#include "common/xstring.h"
using namespace mustard;

int * get_next(const char * t, int t_len)
{
    int * next = new int[t_len + 1];
    next[0] = -1;

    int i = 0, j = -1;
    while (i < t_len) {
        if (j == -1 || t[i] == t[j]) {
            ++i;
            ++j;
            if (t[i] == t[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }

    return next;
}

int match(const char * s, int i, const char * t, int * next, int t_len)
{
    int j = 0;
    while (s[i] && j < t_len) {
        if (j == -1 || s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    return (j == t_len) ? (i - j) : -1;
}
#include <iostream>
char * remove_sub(const char * s, const char * t)
{
    if (!s) {
        return NULL;
    } else if (!t || !*t) {
        return xstring::clone(s);
    }

    int s_len = (int) strlen(s);
    int t_len = (int) strlen(t);

    char * buffer = new char[s_len + 1];
    int b = 0;

    int * next = get_next(t, t_len);

    int i = 0, p = 0;
    while ((p = match(s, i, t, next, t_len)) != -1) {
        strncpy(buffer + b, s + i, p - i);
        b += (p - i);
        i = p + t_len;
    }

    strncpy(buffer + b, s + i, s_len - i);
    b += (s_len - i);
    buffer[b] = 0;

    char * new_str = new char[b + 1];
    strcpy(new_str, buffer);

    delete[] next;
    delete[] buffer;

    return new_str;
}
