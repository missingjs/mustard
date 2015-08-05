#include <cstddef>
#include <iostream>
#include <stack>

struct _pp
{
    int state;

    char *str, *b, *e;
    char *p;

    _pp(char * str, char * b, char * e)
        : state(0), str(str), b(b), e(e), p(NULL)
    {}
};

void print_permutation(char * str, int len)
{
    if (!str || len <= 0) {
        return;
    }

    std::stack<_pp> stk;
    stk.push(_pp(str, str, str + len));

    while (!stk.empty()) {
        _pp & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.b == top.e) {
                    for (top.b = str; top.b != top.e; ++top.b) {
                        std::cout << *top.b << ' ';
                    }
                    std::cout << '\n';
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(_pp(top.str, top.b + 1, top.e));
                }
                break;
            case 1:
                top.p = top.b + 1;
                if (top.p != top.e) {
                    char tmp = *top.b;
                    *top.b = *top.p;
                    *top.p = tmp;
                    top.state = 2;
                    stk.push(_pp(top.str, top.b + 1, top.e));
                } else {
                    stk.pop();
                }
                break;
            case 2:
                char tmp = *top.b;
                *top.b = *top.p;
                *top.p = tmp;
                ++top.p;
                if (top.p != top.e) {
                    char tmp = *top.b;
                    *top.b = *top.p;
                    *top.p = tmp;
                    top.state = 2;
                    stk.push(_pp(top.str, top.b + 1, top.e));
                } else {
                    stk.pop();
                }
                break;
        }
    }
}

