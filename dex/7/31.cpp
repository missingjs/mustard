// @mission: 求有向图强连通分量
#include "31.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    get_scc(g);
    delete g;
    return 0;
}
