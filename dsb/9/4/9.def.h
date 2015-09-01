#include "common/graph.h"
using namespace mustard;

typedef matrix::common_matrix<int> mx_t;
typedef graph::directed_network<char,int,mx_t> graph_t;

char get_center_point(graph_t * g);
