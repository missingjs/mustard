#include <cstring>
#include <cstddef>

int * get_next(const char * pat, int len)
{
    int * next = new int[len+1];
    next[0] = -1;

    int i = 0, j = -1;
    while (i < len) {
        if (j == -1 || pat[i] == pat[j]) {
            ++i;
            ++j;
            if (pat[i] != pat[j]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }

    return next;
}

int match(const char * str, int i, const char * pat, int * next, int len)
{
    int j = 0;
    while (str[i] && j < len) {
        if (j == -1 || str[i] == pat[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    return (j == len) ? i - j : -1;
}

char * str_clone(const char * str)
{
    char * c = new char[strlen(str) + 1];
    strcpy(c, str);
    return c;
}

char * replace(const char * str, const char * pat, const char * rep)
{
    if (!str || !pat || !rep) {
        if (!str) {
            return NULL;
        } else {
            return str_clone(str);
        }
    }

    int str_len = (int) strlen(str);
    int pat_len = (int) strlen(pat);
    if (pat_len == 0) {
        return str_clone(str);
    }
    int rep_len = (int) strlen(rep);

    int * next = get_next(pat, pat_len);

    char * buffer = new char[(str_len/pat_len + 1) * rep_len + 1];
    int b = 0;
    int i = 0, p = 0;
    while ((p = match(str, i, pat, next, pat_len)) != -1) {
        strncpy(buffer + b, str + i, p - i);
        b += (p-i);
        strncpy(buffer + b, rep, rep_len);
        b += rep_len;
        i = p + pat_len;
    }

    strncpy(buffer + b, str + i, str_len - i);
    b += (str_len - i);
    buffer[b] = 0;

    delete[] next;

    char * new_str = new char[b + 1];
    strcpy(new_str, buffer);
    delete[] buffer;
    return new_str;
}
