#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void _link(node_t * root, node_t * & last)
{
    if (!root) {
        return;
    }

    if (!root->lc && !root->rc) {
        last->rc = root;
        last = root;
        return;
    }

    _link(root->lc, last);
    _link(root->rc, last);
}

void print_link_leaf(node_t * h);
node_t * link_leaf(node_t * root)
{
    if (!root) {
        return NULL;
    }
    node_t head, *last = &head;
    _link(root, last);
    node_t * r = head.rc;
    head.rc = NULL;
    return r;
}

void print_link_leaf(node_t * h)
{
    while (h) {
        std::cout << h->data << ' ';
        h = h->rc;
    }
    std::cout << '\n';
}

void delink_leaf(node_t * h)
{
    while (h) {
        node_t *p = h;
        h = h->rc;
        p->rc = NULL;
    }
}
