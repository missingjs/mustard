#include <cstddef>
#include <cstring>
#include <stack>

void reverse_local(char * str)
{
    if (!str || !*str || !*(str+1)) {
        return;
    }

    reverse_local(str + 1);
    char ch = *str;
    char * p = str + 1;
    for (; *p; ++p) {
        *(p-1) = *p;
    }
    *(p-1) = ch;
}

void _rev(const char * str, int len, int p, char * rv)
{
    if (p == len - 1) {
        rv[0] = str[p];
        return;
    }

    rv[len - 1 - p] = str[p];
    _rev(str, len, p + 1, rv);
}

void _r2(const char * str, int p, char * rv)
{
    if (!str[p]) {
        return;
    }

    rv[p] = str[p];
    _r2(str, p + 1, rv);
    char ch = rv[p];
    int i = p + 1;
    for (; rv[i]; ++i) {
        rv[i-1] = rv[i];
    }
    rv[i-1] = ch;
}

char * reverse(const char * str)
{
    if (!str) {
        return NULL;
    }

    int len = (int) strlen(str);
    char * rev = new char[len + 1];
    rev[len] = 0;
    if (len == 0) {
        return rev;
    }
    
    // _rev(str, len, 0, rev);
    _r2(str, 0, rev);

    return rev;
}
