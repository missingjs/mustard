#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<int> list_t;
typedef typename list_t::node arc_t;
typedef graph::undirected_network<char,int,list_t> graph_t;

void kruskal_print_edge(graph_t * g);
