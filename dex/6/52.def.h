#include "common/bitree.h"
using namespace mustard;

struct Lnode : public bitree::ch_data
{
    int level;
    Lnode(char ch = 0, int level = 0)
        : bitree::ch_data(ch), level(level)
    {}
};

typedef bitree::node<Lnode> node_t;

int get_flourish(node_t * root);
