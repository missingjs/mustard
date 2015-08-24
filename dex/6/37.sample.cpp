#include "common/bitree.h"
#include <stack>
using namespace mustard;

typedef bitree::node<char> node_t;

void print_pre_order(node_t * root)
{
    std::stack<node_t*> stk;
    node_t * p = root;

    while (p || !stk.empty()) {
        while (p) {
            stk.push(p);
            std::cout << p->data << ' ';
            p = p->lc;
        }

        p = stk.top()->rc;
        stk.pop();
    }

    std::cout << '\n';
}
