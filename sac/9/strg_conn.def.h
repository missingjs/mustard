#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> list_t;
typedef graph::directed_graph<char,list_t> graph_t;

void print_strongly_connected_components(graph_t * g);
