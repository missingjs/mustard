#include "40.def.h"

void init(node_t * root)
{
    if (root) {
        if (root->lc) {
            root->lc->data.parent = root;
            init(root->lc);
        }
        if (root->rc) {
            root->rc->data.parent = root;
            init(root->rc);
        }
    }
}

void in_order_traverse(node_t * root)
{
    node_t * p = root;
    while (p) {
        while (p->lc) {
            p = p->lc;
        }

        std::cout << p->data << ' ';

        if (p->rc) {
            p = p->rc;
        } else {
            do {
                node_t * c = p;
                p = p->data.parent;
                if (p && c == p->lc) {
                    std::cout << p->data << ' ';
                    if (p->rc) {
                        p = p->rc;
                        break;
                    }
                }
            } while (p);
        }
    }
    std::cout << '\n';
}
