#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void print_post_order(node_t * root)
{
    if (!root) {
        return;
    }

    std::stack<node_t*> stk;
    std::stack<int> flags;

    node_t * p = root;
    while (p || !stk.empty()) {
        while (p) {
            stk.push(p);
            flags.push(0);
            p = p->lc;
        }

        while (!stk.empty()) {
            if (flags.top() == 0) {
                flags.top() = 1;
                p = stk.top()->rc;
                break;
            } else {
                std::cout << stk.top()->data << ' ';
                stk.pop();
                flags.pop();
            }
        }
    }

    /*
    stk.push(root);
    flags.push(0);

    while (!stk.empty()) {
        switch (flags.top()) {
            case 0:
                flags.top() = 1;
                if (stk.top()->lc) {
                    stk.push(stk.top()->lc);
                    flags.push(0);
                }
                break;
            case 1:
                flags.top() = 2;
                if (stk.top()->rc) {
                    stk.push(stk.top()->rc);
                    flags.push(0);
                }
                break;
            case 2:
                std::cout << stk.top()->data << ' ';
                stk.pop();
                flags.pop();
                break;
        }
    }
    */

    std::cout << '\n';
}
