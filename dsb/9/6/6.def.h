#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<int> list_t;
typedef typename list_t::node arc_t;
typedef graph::directed_network<char,int,list_t> graph_t;

void print_all_critical_act(graph_t * g);
