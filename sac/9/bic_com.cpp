// @mission: find all biconnected components
#include "bic_com.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    print_biconnected_components(g);
    delete g;
    return 0;
}
