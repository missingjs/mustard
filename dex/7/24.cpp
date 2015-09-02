// @mission: 利用栈基本操作，非递归遍历强连通图
#include "24.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    traverse_non_recursive(g);
    delete g;
    return 0;
}
