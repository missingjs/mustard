// @mission: single-source shortest path with negative weight
#include <iostream>
#include "ne_short_path.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char s;
    std::cin >> s;
    negative_weight_shortest_path(g, s);
    delete g;
    return 0;
}
