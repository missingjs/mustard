// @mission: 实现Kruskal算法
#include "15.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    kruskal_print_edge(g);
    delete g;
    return 0;
}
