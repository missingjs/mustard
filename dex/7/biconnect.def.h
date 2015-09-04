#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> list_t;
typedef typename list_t::node arc_t;
typedef graph::undirected_graph<char,list_t> graph_t;

void biconnected_component(graph_t * g);
