#include "39.def.h"

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

void post_order_traverse(node_t * root)
{
    if (!root) {
        return;
    }

    node_t * p = root;
    while (p) {
        switch (p->data.mark) {
            case 0:
                p->data.mark = 1;
                if (p->lc) {
                    p = p->lc;
                }
                break;
            case 1:
                p->data.mark = 2;
                if (p->rc) {
                    p = p->rc;
                }
                break;
            case 2:
                std::cout << p->data << ' ';
                p = p->data.parent;
        }
    }

    std::cout << '\n';
}
