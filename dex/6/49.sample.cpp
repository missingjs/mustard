#include "common/bitree.h"
#include <queue>
using namespace mustard;

typedef bitree::node<char> node_t;

bool is_complete(node_t * t)
{
    if (!t) {
        return true;
    }

    std::queue<node_t*> qu;
    qu.push(t);

    bool last = false;
    while (!qu.empty()) {
        node_t * f = qu.front();
        qu.pop();
        if (!last && (!f->lc || !f->rc)) {
            if (!f->rc) {
                last = true;
            } else {
                return false;
            }
        } else if (last && (f->lc || f->rc)) {
            return false;
        }
        if (f->lc) {
            qu.push(f->lc);
        }
        if (f->rc) {
            qu.push(f->rc);
        }
    }
    return true;
}
