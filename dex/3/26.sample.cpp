#include <stack>
#include <cstdlib>

double m1(double a, double p, double e)
{
    double k = abs(p*p - a);
    if (k < e) {
        return p;
    } else {
        return m1(a, (p + a/p)/2, e);
    }
}

double m_sqrt(double a)
{
    double p = a / 2;
    double e = 0.000001;
    return m1(a,p,e);
}

struct _ss
{
    double a,p,e;
    double * ret;
    int state;
    double s1;
    _ss(double a, double p, double e, double * ret)
        : a(a), p(p), e(e), ret(ret), state(0), s1(0.0)
    {}
};

double m_sqrt2(double a)
{
    double p = a/2, e = 0.000001;
    std::stack<_ss> stk;
    double result = 0.0;
    stk.push(_ss(a,p,e,&result));

    double k = 0.0;
    while (!stk.empty()) {
        _ss & top = stk.top();
        switch (top.state) {
            case 0:
                k = abs(top.p * top.p - top.a);
                if (k < top.e) {
                    *top.ret = top.p;
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(_ss(top.a, (top.p + top.a/top.p)/2, top.e, &top.s1));
                }
                break;
            case 1:
                *top.ret = top.s1;
                stk.pop();
                break;
        }
    }

    return result;
}
