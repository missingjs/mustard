// @mission: Dijkstra single-source shortest path
#include <iostream>
#include "dijk.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char s;
    std::cin >> s;
    dijk_shortest_path(g, s);
    delete g;
    return 0;
}
