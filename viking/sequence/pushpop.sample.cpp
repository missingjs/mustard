#include <cstring>
#include <iostream>

void _pp(const char * ib, const char * ie,
        char * stk, int top, char * ob, char * oe)
{
    if (ib == ie && top == 0) {
        *oe = 0;
        std::cout << ob << '\n';
        return;
    }

    if (ib != ie) {
        stk[top] = *ib;
        _pp(ib + 1, ie, stk, top + 1, ob, oe);
    }

    if (top > 0) {
        char top_c = stk[top-1];
        *oe = top_c;
        _pp(ib, ie, stk, top - 1, ob, oe + 1);
        stk[top-1] = top_c;
    }
}

void all_pushpop(const char * seq)
{
    if (!seq || !*seq) {
        return;
    }

    size_t len = strlen(seq);
    char * buf = new char[len + 1];
    char * stk = new char[len];
    
    _pp(seq, seq + len, stk, 0, buf, buf);

    delete[] buf;
    delete[] stk;
}
