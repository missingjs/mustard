// @mission: biconnected graph, print all articulation points, if any.
#include "biconnect.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    print_articulation_points(g);
    delete g;
    return 0;
}
