#include "6.def.h"
#include <vector>
#include <stack>
#include <queue>

bool _topo_act(list_t * L, std::vector<int> & ve, std::stack<int> & stk)
{
    int C = (int) ve.size();
    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        for (; p; p = p->next) {
            indeg[p->adj]++;
        }
    }

    int k = 0;
    for (; k < C; ++k) {
        if (indeg[k] == 0) {
            break;
        }
    }

    if (k == C) {
        return false;
    }

    std::queue<int> qu;
    qu.push(k);
    while (!qu.empty()) {
        int f = qu.front();
        stk.push(f);
        qu.pop();
        arc_t * p = L->_heads[f];
        for (; p; p = p->next) {
            int e = ve[f] + p->weight;
            if (e > ve[p->adj]) {
                ve[p->adj] = e;
            }
            --indeg[p->adj];
            if (indeg[p->adj] == 0) {
                qu.push(p->adj);
            }
        }
    }
    return true;
}

void print_all_critical_act(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> ve(C, 0);
    std::stack<int> stk;

    if (!_topo_act(L, ve, stk)) {
        std::cout << "loop exist!\n";
        return;
    }

    std::vector<int> vl(C, ve[stk.top()]);
    stk.pop();

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        arc_t * p = L->_heads[v];
        while (p) {
            int k = vl[p->adj] - p->weight;
            if (k < vl[v]) {
                vl[v] = k;
            }
            p = p->next;
        }
    }

    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        while (p) {
            int E = ve[i];
            int L = vl[p->adj] - p->weight;
            if (E == L) {
                std::cout << g->vex(i) << " -> " << g->vex(p->adj) << '\n';
            }
            p = p->next;
        }
    }
}

