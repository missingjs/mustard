#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

node_t * mirror_clone(node_t * root)
{
    if (!root) {
        return NULL;
    }

    node_t * cr = new node_t(root->data);

    node_t * lc = mirror_clone(root->lc);
    node_t * rc = mirror_clone(root->rc);
    cr->lc = rc;
    cr->rc = lc;

    return cr;
}
