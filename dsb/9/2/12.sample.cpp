#include "12.def.h"
#include <queue>
#include <cstring>

typedef typename struct_t::node arc_t;

char farest_vex(graph_t * g, char v)
{
    std::queue<int> qu;
    int * level = new int[g->vex_count()];
    memset(level, 0, sizeof(int) * g->vex_count());

    int k = g->id(v);
    level[k] = 1;
    qu.push(k);

    while (!qu.empty()) {
        int f = qu.front();
        qu.pop();
        arc_t * p = g->get_structure()->_heads[f];
        while (p) {
            int adj = p->adj;
            if (!level[adj]) {
                level[adj] = level[f] + 1;
                qu.push(adj);
            }
            p = p->next;
        }
    }

    int max_i = 0;
    for (int i = 1; i < g->vex_count(); ++i) {
        if (level[i] > level[max_i]) {
            max_i = i;
        }
    }

    delete[] level;
    return g->vex(max_i);
}
