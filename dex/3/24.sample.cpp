#include <stack>

int g(int m, int n)
{
    if (n < 0) {
        return 0;
    } else if (m == 0) {
        return 0;
    } else {
        return g(m - 1, 2 * n) + n;
    }
}

struct _gs
{
    int m, n;
    int * ret;
    int state;
    int g1;
    _gs(int m, int n, int * ret)
        : m(m), n(n), ret(ret), state(0), g1(0)
    {}
};

int g2(int m, int n)
{
    std::stack<_gs> stk;
    int result = 0;
    stk.push(_gs(m,n,&result));

    while (!stk.empty()) {
        _gs & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.n < 0) {
                    *top.ret = 0;
                    stk.pop();
                } else if (top.m == 0) {
                    *top.ret = 0;
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(_gs(top.m-1, 2*top.n, &top.g1));
                }
                break;
            case 1:
                *top.ret = top.g1 + top.n;
                stk.pop();
                break;
        }
    }

    return result;
}
