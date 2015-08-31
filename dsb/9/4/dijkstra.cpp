// @mission: 实现Dijkstra算法，打印出最短路径即可

#include "dijkstra.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char start = 0;
    std::cin >> start;
    dijkstra_show_all_path(g, start);
    delete g;
    return 0;
}

