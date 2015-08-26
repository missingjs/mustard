#include "68.def.h"
#include <queue>

struct dual
{
    node_t * node;
    int degree;
    dual(node_t * n, int d)
        : node(n), degree(d)
    {}
};

node_t * build_by_seq_degree(int n, const char * ch, const int * deg)
{
    if (n <= 0 || !ch || !deg) {
        return NULL;
    }

    node_t * root = new node_t(ch[0]);
    std::queue<dual> qu;
    qu.push(dual(root, deg[0]));

    int i = 1;
    node_t * last = root;
    while (!qu.empty()) {
        dual & d = qu.front();
        if (d.degree) {
            node_t * n = new node_t(ch[i]);
            qu.push(dual(n, deg[i]));
            ++i;
            if (!d.node->lc) {
                d.node->lc = n;
            } else {
                last->rc = n;
            }
            last = n;
            --d.degree;
        } else {
            qu.pop();
        }
    }
    return root;
}
