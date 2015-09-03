#include "common/bitree.h"
#include "common/graph.h"
using namespace mustard;

typedef char vex_t;
typedef int weight_t;
typedef bitree::node<vex_t> tree_t;
typedef matrix::symmetric_matrix<weight_t> mx_t;
typedef graph::undirected_network<vex_t,weight_t,mx_t> graph_t;

tree_t * prim_mst_forest(graph_t * g);
