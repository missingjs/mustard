#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

char * f1(const char * str)
{
    if (!str) {
        return NULL;
    }

    int index = 0, length = 0, length1, i = 0, j, k;
    int len = (int) strlen(str);
    while (i < len) {
        j = i + 1;
        while (j < len) {
            if (str[i] == str[j]) {
                length1 = 1;
                for (k = 1; str[i+k] == str[j+k]; ++k) {
                    length1++;
                }
                if (length1 > length) {
                    index = i;
                    length = length1;
                }
                // j += length1;
            }
            ++j;
        }
        ++i;
    }
    char * t = new char[length+1];
    strncpy(t, str + index, length);
    t[length] = 0;
    return t;
}

int do_cmp(const char * p1, const char * p2)
{
    int len = 0;
    while (*p1 && *p2 && *p1++ == *p2++) {
        ++len;
    }
    return len;
}

char * f2(const char * str)
{
    int max_len = 0, start = 0;

    for (int i = 0; str[i]; ++i) {
        for (int j = i + 1; str[j]; ++j) {
            int len = do_cmp(str + i, str + j);
            if (len > max_len) {
                max_len = len;
                start = i;
            }
        }
    }

    char * r = new char[max_len + 1];
    strncpy(r, str + start, max_len);
    r[max_len] = 0;
    return r;
}

int _cmp(const void * p1, const void * p2)
{
    return strcmp(*(const char **)p1, *(const char **)p2);
}

struct c_cmp
{
    bool operator() (const char * p1, const char * p2)
    {
        return strcmp(p1, p2) < 0;
    }
};

char * f3(const char * str)
{
    int len = (int) strlen(str);
    const char ** suff = new const char* [len];

    for (int i = 0; i < len; ++i) {
        suff[i] = str + i;
    }

    // qsort(suff, len, sizeof(const char *), _cmp);
    std::sort(suff, suff + len, c_cmp());

    int max_len = 0, index = 0;
    for (int i = 0; i < len - 1; ++i) {
        int len = do_cmp(suff[i], suff[i+1]);
        if (len > max_len) {
            max_len = len;
            index = i;
        }
    }

    char * t = new char[max_len + 1];
    strncpy(t, suff[index], max_len);
    t[max_len] = 0;
    return t;
}

char * longest_repeat_str(const char * str)
{
    return f3(str);
}
