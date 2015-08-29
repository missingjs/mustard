#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> struct_t;
typedef graph::undirected_graph<char,struct_t> graph_t;

bool is_tree(graph_t * g);
