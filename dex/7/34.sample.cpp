#include "34.def.h"
#include <vector>
#include <queue>

std::vector<int> _topo_sort(list_t * L, int C)
{
    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        for (; p; p = p->next) {
            ++indeg[p->adj];
        }
    }

    std::queue<int> qu;
    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            qu.push(i);
        }
    }

    std::vector<int> seq;
    while (!qu.empty()) {
        int f = qu.front();
        seq.push_back(f);
        qu.pop();
        for (arc_t * p = L->_heads[f]; p; p = p->next) {
            --indeg[p->adj];
            if (indeg[p->adj] == 0) {
                qu.push(p->adj);
            }
        }
    }

    return seq;
}

void renumbering(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> topo_seq = _topo_sort(L, C);

    for (int i = 0; i < C; ++i) {
        std::cout << g->vex(topo_seq[i]) << ": "
            << topo_seq[i] << " -> " << i << '\n';
    }
}
