// @mission: 利用Dijkstra算法，求带权有向连通图的最小生成树
// 注意，无向图最小生成树不可用此方法生成，参见case[2]
#include "8.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    print_MST(g);
    delete g;
    return 0;
}
