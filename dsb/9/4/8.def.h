#include "common/graph.h"
#include "common/matrix2.h"
using namespace mustard;

typedef matrix::common_matrix<int> mx_t;
typedef graph::directed_network<char,int,mx_t> graph_t;

void print_MST(graph_t * g);
