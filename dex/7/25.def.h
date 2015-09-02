#include "common/graph.h"
#include <vector>
using namespace mustard;

typedef graph::adj_list<bool> list_t;
typedef typename list_t::node arc_t;
typedef graph::directed_graph<char,list_t> graph_t;

void build(graph_t * g, std::vector<int> & s, 
        std::vector<int> & fst,
        std::vector<int> & lst);
bool has_loop(
        const std::vector<int> & s,
        const std::vector<int> & fst,
        const std::vector<int> & lst);
