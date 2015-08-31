#include "common/graph.h"
#include "common/matrix.h"
using namespace mustard;

typedef matrix::common_matrix<int> mx_t;
typedef graph::directed_network<char,int,mx_t> graph_t;

void floyd_print_all_path(graph_t * g);
