#include "common/bitree.h"
using namespace mustard;

struct pnode : public bitree::ch_data
{
    typedef bitree::node<pnode> binode_t;
    binode_t * parent;
    pnode(char ch = 0, binode_t * parent = NULL)
        : bitree::ch_data(ch), parent(parent)
    {}
};

typedef bitree::node<pnode> node_t;

void init(node_t * root);

void in_order_traverse(node_t * root);
