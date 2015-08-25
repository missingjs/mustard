#include "52.def.h"
#include <queue>

int get_flourish(node_t * root)
{
    if (!root) {
        return 0;
    }

    std::queue<node_t*> qu;
    qu.push(root);
    root->data.level = 1;

    int n_max = 0, level = 0, cc = 0;
    while (!qu.empty()) {
        node_t * f = qu.front();
        if (f->data.level == level) {
            ++cc;
        } else {
            level = f->data.level;
            cc = 1;
        }
        if (cc > n_max) {
            n_max = cc;
        }
        if (f->lc) {
            f->lc->data.level = level + 1;
            qu.push(f->lc);
        }
        if (f->rc) {
            f->rc->data.level = level + 1;
            qu.push(f->rc);
        }
        qu.pop();
    }

    return level * n_max;
}
