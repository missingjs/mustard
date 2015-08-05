int akm_1(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return akm_1(m - 1, 1);
    } else {
        int p = akm_1(m, n - 1);
        return akm_1(m - 1, p);
    }
}

struct _akm
{
    int state;
    int m, n, p;
    int * ret;

    _akm(int m, int n, int * ret)
        : state(0), m(m), n(n), p(0), ret(ret)
    {}
};

#include <stack>

int akm_2(int m, int n)
{
    std::stack<_akm> stk;
    int result = 0;
    stk.push(_akm(m,n,&result));

    while (!stk.empty()) {
        _akm & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.m == 0) {
                    *top.ret = top.n + 1;
                    stk.pop();
                } else if (top.n == 0) {
                    top.state = 1;
                    stk.push(_akm(top.m - 1, 1, &top.p));
                } else {
                    top.state = 2;
                    stk.push(_akm(top.m, top.n-1, &top.p));
                }
                break;
            case 2:
                top.state = 3;
                stk.push(_akm(top.m-1, top.p, &top.p));
                break;
            case 1:
            case 3:
                *top.ret = top.p;
                stk.pop();
                break;
        }
    }

    return result;
}

