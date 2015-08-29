// @mission: 求顶点v到顶点u的所有简单路径
#include "17.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    char v, u;
    std::cin >> v >> u;

    print_all_path(g, v, u);

    delete g;
    return 0;
}
