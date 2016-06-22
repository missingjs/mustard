// @mission: Strongly Connected Components
#include "strg_conn.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    print_strongly_connected_components(g);
    delete g;
    return 0;
}
