// @mission: 实现逆向拓扑排序
#include "8.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    print_reverse_topological_seq(g);
    delete g;
    return 0;
}
