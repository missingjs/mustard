#include "common/graph.h"
using namespace mustard;

typedef matrix::common_matrix<bool> mx_t;
typedef graph::directed_graph<char,mx_t> graph_t;

int find_num_of_path(graph_t * g, char i, char j, int k);
