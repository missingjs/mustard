#include <stack>

int F(int n)
{
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return n * F(n / 2);
    }
}

struct _fs
{
    int n;
    int * ret;
    int state;
    int f1;
    _fs(int n, int * ret)
        : n(n), ret(ret), state(0), f1(0)
    {}
};

int F2(int n)
{
    std::stack<_fs> stk;
    int result = 0;
    stk.push(_fs(n, &result));

    while (!stk.empty()) {
        _fs & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.n < 0) {
                    *top.ret = 0;
                    stk.pop();
                } else if (top.n == 0) {
                    *top.ret = 1;
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(_fs(top.n/2, &top.f1));
                }
                break;
            case 1:
                *top.ret = top.n * top.f1;
                stk.pop();
        }
    }

    return result;
}
