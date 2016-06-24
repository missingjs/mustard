#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<int> list_t;
typedef graph::directed_network<char,int,list_t> graph_t;

void topo_shortest_path(graph_t * g, char s);
