#include "common/graph.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;
typedef graph::directed_network<int,int,matrix_t> graph_t;

void network_flow_process(graph_t * g, int begin, int end);

