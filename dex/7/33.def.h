#include "common/bitree.h"
#include "common/graph.h"
#include <vector>
using namespace mustard;

typedef char vex_t;
typedef int weight_t;
typedef matrix::symmetric_matrix<weight_t> mx_t;
typedef graph::undirected_network<vex_t,weight_t,mx_t> graph_t;
typedef bitree::node<vex_t> tree_t;

struct EdgeSet
{
    struct edge 
    {
        int i, j;
        weight_t w;
        edge(int i=0, int j=0, int w=0)
            : i(i), j(j), w(w)
        {}
    };

    std::vector<edge> edge_list;
};
void GetMinEdge(EdgeSet * s, int & u, int & v);
void DelMinEdge(EdgeSet * s);

EdgeSet * build_edge_set(graph_t * g);
tree_t * kruskal_tree(graph_t * g, EdgeSet * s);
