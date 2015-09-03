// @mission: 修改Prim算法，求图的最小生成森林（以孩子-兄弟链表存储）
#include "32.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    tree_t * tree = prim_mst_forest(g);
    bitree::print(tree, bitree::CHILD_SIBLING_FORMAT);
    delete g;
    bitree::free(tree);
    return 0;
}
