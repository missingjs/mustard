#include <iostream>

void h1(int n, char a, char b, char c)
{
    if (n > 0) {
        h1(n - 1, a, c, b);
        std::cout << a << " --> " << c << std::endl;
        h1(n - 1, b, a, c);
    }
}

void hanoi(int n)
{
    h1(n, 'x', 'y', 'z');
}

struct hs
{
    int n;
    char a, b, c;
    int state;

    hs(int n, char a, char b, char c)
        : n(n), a(a), b(b), c(c), state(0)
    {}
};

#include <stack>

void hanoi_2(int n)
{
    std::stack<hs> stk;
    stk.push(hs(n,'x','y','z'));

    while (!stk.empty()) {
        hs & top = stk.top();
        switch (top.state) {
            case 0:
                if (top.n > 0) {
                    top.state = 1;
                    stk.push(hs(top.n-1, top.a, top.c, top.b));
                } else {
                    stk.pop();
                }
                break;
            case 1:
                std::cout << top.a << " --> " << top.c << std::endl;
                top.state = 2;
                stk.push(hs(top.n-1, top.b, top.a, top.c));
                break;
            case 2:
                stk.pop();
                break;
        }
    }
}
