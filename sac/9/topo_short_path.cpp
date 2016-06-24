// @mission: single-source shortest path by topological sorting
#include <iostream>
#include "topo_short_path.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char s;
    std::cin >> s;
    topo_shortest_path(g, s);
    delete g;
    return 0;
}
