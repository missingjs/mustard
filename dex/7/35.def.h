#include "common/graph.h"
using namespace mustard;

typedef matrix::common_matrix<bool> mx_t;
typedef graph::directed_graph<char, mx_t> graph_t;

void find_root(graph_t * g);
