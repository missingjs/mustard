#include "40.def.h"

snode * _fk(snode * root, int k, int s)
{
    if (!root) {
        return NULL;
    }

    if (root->Lsize + s == k) {
        return root;
    }

    if (root->Lsize + s > k) {
        return _fk(root->lc, k, s);
    }
    else {
        return _fk(root->rc, k, root->Lsize + s);
    }
}

snode * find_kth(snode * root, int k)
{
    if (!root) {
        return NULL;
    }

    return _fk(root, k, 0);
}

snode * _conv(node_t * root, int & c)
{
    if (!root) {
        c = 0;
        return NULL;
    }

    snode * s = new snode(root->data);
    int Lc = 0;

    snode * lc = _conv(root->lc, Lc);
    s->lc = lc;
    s->Lsize = Lc + 1;

    int Rc = 0;
    snode * rc = _conv(root->rc, Rc);
    s->rc = rc;

    c = Lc + Rc + 1;
    return s;
}

snode * to_stree(node_t * root)
{
    int c = 0;
    return _conv(root, c);
}

void release(snode * root)
{
    if (root) {
        release(root->lc);
        release(root->rc);
        delete root;
    }
}

