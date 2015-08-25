#include "66.def.h"

node_t * create_child_sibling(int n, const char * ch, const int * pr)
{
    node_t ** nodes = new node_t*[n];

    node_t * root = new node_t(ch[0]);
    nodes[0] = root;

    for (int i = 1; i < n; ++i) {
        int p = pr[i];
        node_t * child = new node_t(ch[i]);
        nodes[i] = child;
        if (pr[i-1] != p) {
            nodes[p]->lc = child;
        } else {
            nodes[i-1]->rc = child;
        }
    }

    return root;
}
