#include <cstddef>
#include <cstring>

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
                j += length1;
            } else {
                ++j;
            }
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

char * longest_repeat_str(const char * str)
{
    return f1(str);
}
