#include "16.def.h"
#include <vector>
#include <cstring>

typedef typename struct_t::node arc_t;

void _pap(
        graph_t * g, struct_t * st, int L, 
        int i, int u, bool * visited, 
        std::vector<char> path)
{
    if (i == u) {
        if ((int) path.size() == L) {
            for (size_t j = 0; j < path.size(); ++j) {
                std::cout << path[j] << ' ';
            }
            std::cout << g->vex(u) << '\n';
        }
        return;
    }

    if ((int) path.size() == L + 1) {
        return;
    }

    path.push_back(g->vex(i));
    visited[i] = true;
    for (arc_t * p = st->_heads[i]; p; p = p->next) {
        if (!visited[p->adj]) {
            _pap(g,st,L,p->adj,u,visited,path);
        }
    }
    visited[i] = false;
    path.pop_back();
}

void print_all_path(graph_t * g, int L, char v, char u)
{
    std::vector<char> path;
    int k = g->vex_count();
    bool * visited = new bool[k];
    memset(visited, 0, sizeof(bool) * k);
    _pap(g, g->get_structure(), L, g->id(v), 
            g->id(u), visited, path);
    delete[] visited;
}
