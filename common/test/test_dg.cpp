#include "common/graph.h"
using namespace mustard;

int main()
{
    typedef matrix::common_matrix<bool> mx_t;
    typedef graph::directed_graph<char,mx_t> g_t;

    g_t * graph = graph::read_graph<g_t>();
    graph->display(std::cout);

    delete graph;
    return 0;
}
