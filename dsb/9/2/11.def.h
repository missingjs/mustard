#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> adj_list_t;
typedef graph::undirected_graph<char,adj_list_t> graph_t;

void dfs(graph_t * g, char start);
