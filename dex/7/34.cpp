// @mission: 给有向无环图G中每个顶点赋以一个整数序号，并满足以下条件：若从顶点i至顶点j有一条弧，则应使i<j.
#include "34.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    renumbering(g);
    delete g;
    return 0;
}
