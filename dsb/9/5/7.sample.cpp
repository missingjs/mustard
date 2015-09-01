#include "7.def.h"
#include <vector>
#include <queue>

bool test_loop_exists(graph_t * g)
{
    if (!g || g->vex_count() < 3) {
        return false;
    }

    int C = g->vex_count();
    std::vector<int> indeg(C, 0);
    list_t * L = g->get_structure();

    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        while (p) {
            ++indeg[p->adj];
            p = p->next;
        }
    }

    int i = 0;
    for (; i < C; ++i) {
        if (indeg[i] == 0) {
            break;
        }
    }
    if (i == C) {
        return false;
    }

    std::queue<int> qu;
    qu.push(i);

    int n = 0;
    while (!qu.empty()) {
        int f = qu.front();
        qu.pop();
        ++n;
        arc_t * p = L->_heads[f];
        while (p) {
            --indeg[p->adj];
            if (indeg[p->adj] == 0) {
                qu.push(p->adj);
            }
            p = p->next;
        }
    }

    return n == C;
}
