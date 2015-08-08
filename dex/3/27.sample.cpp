#include <stack>

int akm(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return akm(m - 1, 1);
    } else {
        return akm(m - 1, akm(m, n - 1));
    }
}

struct _as
{
    int m, n;
    int * ret;
    int state;
    int a1, a2;
    _as(int m, int n, int * ret)
        : m(m), n(n), ret(ret), state(0), a1(0), a2(0)
    {}
};

int akm2(int m, int n)
{
    std::stack<_as> stk;
    int result = 0;
    stk.push(_as(m,n,&result));

    while (!stk.empty()) {
        _as & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.m == 0) {
                    *top.ret = top.n + 1;
                    stk.pop();
                } else if (top.n == 0) {
                    top.state = 1;
                    stk.push(_as(top.m-1, 1, &top.a1));
                } else {
                    top.state = 2;
                    stk.push(_as(top.m, top.n - 1, &top.a1));
                }
                break;
            case 1:
                *top.ret = top.a1;
                stk.pop();
                break;
            case 2:
                top.state = 3;
                stk.push(_as(top.m-1, top.a1, &top.a2));
                break;
            case 3:
                *top.ret = top.a2;
                stk.pop();
                break;
        }
    }

    return result;
}
