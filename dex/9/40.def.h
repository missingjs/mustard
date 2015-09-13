#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<int> node_t;

struct snode
{
    int data;
    int Lsize;

    snode *lc, *rc;

    snode(int d = 0)
        : data(d), Lsize(0), lc(NULL), rc(NULL)
    {}
};

snode * to_stree(node_t * root);

snode * find_kth(snode * root, int k);

void release(snode * root);
