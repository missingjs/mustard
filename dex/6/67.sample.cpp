#include "67.def.h"
#include <queue>

node_t * create_by_dual()
{
    char ch = 0;
    std::cin >> ch;   // read '^'
    std::cin >> ch;   // root
    node_t * root = new node_t(ch);

    std::queue<node_t*> qu;
    qu.push(root);

    char parent = 0, child = 0;
    std::cin >> parent >> child;
    node_t * last = root;
    while (!qu.empty()) {
        node_t * f = qu.front();
        if (parent == f->data) {
            node_t * c = new node_t(child);
            qu.push(c);
            if (!f->lc) {
                f->lc = c;
            } else {
                last->rc = c;
            }
            last = c;
            std::cin >> parent >> child;
        } else {
            qu.pop();
        }
    }

    return root;
}
