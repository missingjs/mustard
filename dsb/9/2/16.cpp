// @mission: 求顶点v到顶点u的所有长度为L的简单路径
#include "16.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    int L = 0;
    std::cin >> L;

    char v, u;
    std::cin >> v >> u;

    print_all_path(g, L, v, u);

    delete g;
    return 0;
}
