#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> list_t;
typedef typename list_t::node arc_t;
typedef graph::undirected_graph<char,list_t> graph_t;

void find_len_of_path(graph_t * g, char a, char b, int k);
