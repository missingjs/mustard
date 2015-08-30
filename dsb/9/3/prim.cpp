// @mission: 实现prim算法
#include "prim.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    prim_print_edge(g);
    delete g;
    return 0;
}
