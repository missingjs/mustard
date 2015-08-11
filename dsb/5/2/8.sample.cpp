#include <cstddef>
#include <stack>

bool exists(const char * str, char x)
{
    if (!str || !*str) {
        return false;
    }

    if (*str == x) {
        return true;
    } else {
        return exists(str + 1, x);
    }
}

struct _es
{
    const char * str;
    char x;
    bool * ret;
    int state;
    bool e1;

    _es(const char * str, char x, bool * ret)
        : str(str), x(x), ret(ret), state(0), e1(false)
    {}
};

bool exists2(const char * str, char x)
{
    std::stack<_es> stk;
    bool r = false;

    stk.push(_es(str, x, &r));

    while (!stk.empty()) {
        _es & top = stk.top();
        switch (top.state) {
            case 0:
                if (!top.str || !*top.str) {
                    *top.ret = false;
                    stk.pop();
                    break;
                }
                if (*top.str == top.x) {
                    *top.ret = true;
                    stk.pop();
                    break;
                }
                top.state = 1;
                stk.push(_es(top.str+1, top.x, &top.e1));
                break;
            case 1:
                *top.ret = top.e1;
                stk.pop();
                break;
        }
    }

    return r;
}
