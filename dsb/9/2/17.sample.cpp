#include "17.def.h"
#include <vector>
#include <cstring>

typedef typename struct_t::node arc_t;

void _pap(
        graph_t * g, struct_t * st, 
        int i, int u, bool * visited, 
        std::vector<char> path)
{
    if (i == u) {
        for (size_t j = 0; j < path.size(); ++j) {
            std::cout << path[j] << ' ';
        }
        std::cout << g->vex(u) << '\n';
        return;
    }

    path.push_back(g->vex(i));
    visited[i] = true;
    for (arc_t * p = st->_heads[i]; p; p = p->next) {
        if (!visited[p->adj]) {
            _pap(g,st,p->adj,u,visited,path);
        }
    }
    visited[i] = false;
    path.pop_back();
}

void print_all_path(graph_t * g, char v, char u)
{
    std::vector<char> path;
    int k = g->vex_count();
    bool * visited = new bool[k];
    memset(visited, 0, sizeof(bool) * k);
    _pap(g, g->get_structure(), g->id(v), g->id(u), visited, path);
    delete[] visited;
}
