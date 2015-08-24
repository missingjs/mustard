#include "common/bitree.h"
using namespace mustard;

struct pnode
{
    char ch;
    int mark;
    bitree::node<pnode> * parent;
    pnode(char ch = 0, int mark = 0, 
            bitree::node<pnode> * parent = NULL)
        : ch(ch), mark(mark), parent(parent)
    {}
};

typedef bitree::node<pnode> node_t;

void init(node_t * root);

void post_order_traverse(node_t * root);

std::ostream & operator<<(std::ostream & out, const pnode & n);

std::istream & operator>>(std::istream & in, pnode & n);
