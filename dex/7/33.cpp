// @mission: 参见33.png
#include "33.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    EdgeSet * s = build_edge_set(g);
    tree_t * root = kruskal_tree(g, s);
    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);
    bitree::free(root);
    delete s;
    delete g;
    return 0;
}

