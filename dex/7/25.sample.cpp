#include "25.def.h"
#include <queue>

void build(graph_t * g, std::vector<int> & s, 
        std::vector<int> & fst,
        std::vector<int> & lst)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();
    fst.assign(C, -1);
    lst.assign(C, -2);
    int n = 0;
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        for (; p; p = p->next) {
            s.push_back(p->adj);
            if (fst[i] < 0) {
                fst[i] = n;
            }
            lst[i] = n;
            ++n;
        }
    }
}

bool has_loop(
        const std::vector<int> & s,
        const std::vector<int> & fst,
        const std::vector<int> & lst)
{
    int C = (int) fst.size();

    std::vector<int> indeg(C, 0);

    for (int i = 0; i < C; ++i) {
        for (int j = fst[i]; j <= lst[i]; ++j) {
            indeg[s[j]]++;
        }
    }

    std::queue<int> qu;
    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            qu.push(i);
        }
    }

    int n = 0;
    while (!qu.empty()) {
        int v = qu.front();
        ++n;
        qu.pop();
        for (int i = fst[v]; i <= lst[v]; ++i) {
            indeg[s[i]]--;
            if (indeg[s[i]] == 0) {
                qu.push(s[i]);
            }
        }
    }

    return n == C;
}
