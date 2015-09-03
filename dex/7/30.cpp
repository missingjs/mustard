// @mission: 求有向图G所有简单回路
#include "30.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    print_all_simple_loop(g);
    delete g;
    return 0;
}

