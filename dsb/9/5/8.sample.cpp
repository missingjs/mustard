#include "8.def.h"
#include <vector>

void _dfs(graph_t * g, list_t * L, int s, std::vector<int> & visited)
{
    visited[s] = 1;
    arc_t * p = L->_heads[s];
    while (p) {
        if (!visited[p->adj]) {
            _dfs(g, L, p->adj, visited);
        }
        p = p->next;
    }
    std::cout << g->vex(s) << ' ';
}

void print_reverse_topological_seq(graph_t * g)
{
    if (!g || !g->vex_count()) {
        std::cout << "no seq\n";
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();
    std::vector<int> indeg(C, 0);

    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        while (p) {
            ++indeg[p->adj];
            p = p->next;
        }
    }

    int k = 0;
    for (; k < C; ++k) {
        if (indeg[k] == 0) {
            break;
        }
    }

    if (k == C) {
        std::cout << "loop exist\n";
        return;
    }

    std::vector<int> visited(C, 0);
    _dfs(g, L, k, visited);
    std::cout << '\n';
}
