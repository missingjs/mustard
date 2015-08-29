// @mission: 求无向连通图G中距离顶点v的最远顶点
#include "12.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();

    char v = 0;
    std::cin >> v;

    char k = farest_vex(g, v);
    std::cout << k << '\n';

    delete g;
    return 0;
}
