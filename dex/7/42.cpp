// @mission: 实现Dijkstra算法
#include "42.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char s = 0;
    std::cin >> s;
    all_shortest_path(g, s);
    delete g;
    return 0;
}
