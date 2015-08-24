#include "common/bitree.h"
#include <stack>
using namespace mustard;

typedef bitree::node<char> node_t;

void print_pre_order(node_t * root)
{
    if (!root) {
        return;
    }

    std::stack<node_t*> stk;
    node_t * p = root;
    while (true) {
        while (p) {
            std::cout << p->data << ' ';
            stk.push(p);
            p = p->lc;
        }

        bool found = false;
        while (!stk.empty()) {
            node_t * t = stk.top();
            stk.pop();
            if (t->rc) {
                p = t->rc;
                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }
    }

    std::cout << '\n';
}
