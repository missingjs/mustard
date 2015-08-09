#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

node_t * reverse(node_t * h)
{
    if (!h || !h->next) {
        return h;
    }

    node_t * new_head = reverse(h->next);
    h->next->next = h;
    h->next = NULL;
    return new_head;
}

#include <stack>

struct _rs
{
    node_t * h;
    node_t ** ret;
    int state;
    node_t * new_head;

    _rs(node_t * h, node_t ** ret)
        : h(h), ret(ret), state(0), new_head(NULL)
    {}
};

node_t * reverse2(node_t * h)
{
    std::stack<_rs> stk;
    node_t * nh = NULL;
    stk.push(_rs(h, &nh));

    while (!stk.empty()) {
        _rs & top = stk.top();
        switch (top.state) {
            case 0:
                if (!top.h || !top.h->next) {
                    *top.ret = top.h;
                    stk.pop();
                } else {
                    top.state = 1;
                    stk.push(_rs(top.h->next, &top.new_head));
                }
                break;
            case 1:
                top.h->next->next = top.h;
                top.h->next = NULL;
                *top.ret = top.new_head;
                stk.pop();
                break;
        }
    }

    return nh;
}
