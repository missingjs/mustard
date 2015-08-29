#include "13.def.h"
#include <cstring>

typedef typename graph_t::vex_t vex_t;
typedef typename struct_t::node arc_t;

int _dfs(struct_t * s, int v, bool * visited)
{
    visited[v] = true;
    int a = 0;
    for (arc_t * p = s->_heads[v]; p; p = p->next) {
        ++a;
        if (!visited[p->adj]) {
            a += _dfs(s, p->adj, visited);
        }
    }
    return a;
}

bool is_tree(graph_t * g)
{
    if (!g) {
        return false;
    }
    if (!g->vex_count()) {
        return true;
    }

    int c = g->vex_count();
    bool * visited = new bool[c];
    memset(visited, 0, sizeof(bool)*c);

    int num_arcs = _dfs(g->get_structure(), 0, visited);
    int vc = 0;
    for (int i = 0; i < c; ++i) {
        if (visited[i]) {
            ++vc;
        }
    }

    delete[] visited;

    return vc == c && num_arcs == 2*(c-1);
}

