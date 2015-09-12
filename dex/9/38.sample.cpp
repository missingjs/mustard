#include "38.def.h"
#include <stack>

class _stk
{
    node_t * p;
    std::stack<node_t*> stk;

public:
    _stk(node_t * r)
        : p(NULL), stk()
    {
        _init(r);
    }

    ~_stk() {}

    node_t * next();

    void pop();

    node_t * get() const
    {
        return p;
    }

    node_t * end();

private:
    void _init(node_t * r);
};

void _insert(node_t * p1, node_t * p2);

node_t * merge(node_t * t1, node_t * t2)
{
    _stk s1(t1), s2(t2);

    node_t *p1 = s1.get(), *p2 = s2.get();
    node_t * last_p1 = NULL;
    while (p1 && p2) {
        if (p1->data < p2->data) {
            last_p1 = p1;
            p1 = s1.next();
        }
        else if (p1->data == p2->data) {
            last_p1 = p1;
            p1 = s1.next();
            delete p2;
            s2.pop();
            p2 = s2.get();
        }
        else {
            s2.pop();
            _insert(p1, p2);
            p2 = s2.get();
        }
    }

    if (!p1) {
        last_p1->rc = s2.end();
    }

    return t1;
}

void _stk::_init(node_t * r)
{
    while (r->lc) {
        stk.push(r);
        r = r->lc;
    }
    p = r;
}

node_t * _stk::next()
{
    if (p->rc) {
        p = p->rc;
        while (p->lc) {
            stk.push(p);
            p = p->lc;
        }
    }
    else if (!stk.empty()) {
        p = stk.top();
        stk.pop();
    }
    else {
        p = NULL;
    }
    return get();
}

void _stk::pop()
{
    node_t *rc = p->rc;
    next();
    if (!stk.empty()) {
        stk.top()->lc = rc;
    }
    else if (p) {
        p->lc = rc;
    }
}

void _insert(node_t * p1, node_t * p2)
{
    p2->rc = NULL;
    p2->lc = p1->lc;
    p1->lc = p2;
}

node_t * _stk::end()
{
    while (!stk.empty()) {
        p = stk.top();
        stk.pop();
    }
    return p;
}
