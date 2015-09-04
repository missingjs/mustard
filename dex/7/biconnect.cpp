// @mission: 求关节点（割点）和重连通分量
#include "biconnect.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    biconnected_component(g);
    delete g;
    return 0;
}
