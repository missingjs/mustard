#include "common/graph.h"
#include "common/matrix2.h"
using namespace mustard;

typedef matrix::symmetric_matrix<int> mx_t;
typedef graph::undirected_network<char,int,mx_t> graph_t;

void prim_print_edge(graph_t * g);
