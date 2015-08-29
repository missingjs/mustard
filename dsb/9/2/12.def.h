#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> struct_t;
typedef graph::undirected_graph<char,struct_t> graph_t;

char farest_vex(graph_t * g, char v);

