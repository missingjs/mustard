int fib(int n)
{
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

struct fs
{
    int n;
    int * ret;
    int state;

    int f1, f2;

    fs(int n, int * ret)
        : n(n), ret(ret), state(0), f1(0), f2(0)
    {}
};

#include <stack>

int fib2(int n)
{
    std::stack<fs> stk;
    int result = 0;
    stk.push(fs(n, &result));

    while (!stk.empty()) {
        fs & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.n <= 0) {
                    *top.ret = 0;
                    stk.pop();
                } else if (top.n == 1) {
                    *top.ret = 1;
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(fs(top.n-1, &top.f1));
                }
                break;
            case 1:
                top.state = 2;
                stk.push(fs(top.n-2, &top.f2));
                break;
            case 2:
                *top.ret = top.f1 + top.f2;
                stk.pop();
                break;
        }
    }

    return result;
}
