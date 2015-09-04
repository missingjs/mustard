#include "41.def.h"
#include <vector>
#include <algorithm>

void _dfs(list_t * L, int v, std::vector<int> & visited,
        std::vector<int> & seq)
{
    visited[v] = 1;
    for (arc_t * p = L->_heads[v]; p; p = p->next) {
        if (!visited[p->adj]) {
            _dfs(L, p->adj, visited, seq);
        }
    }
    seq.push_back(v);
}

std::vector<int> _get_indegree(list_t * L, int C)
{
    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            ++indeg[p->adj];
        }
    }
    return indeg;
}

std::vector<int> _topo_sort(list_t * L, int C)
{
    std::vector<int> seq, visited(C, 0);
    std::vector<int> indeg = _get_indegree(L, C);

    int start = -1;
    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            start = i;
            break;
        }
    }

    _dfs(L, start, visited, seq);

    std::reverse(seq.begin(), seq.end());

    return seq;
}

void show_critical_path(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> topo_seq = _topo_sort(L, C);

    std::vector<int> ve(C, 0);
    for (int i = 0; i < C; ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            if (ve[i] + p->weight > ve[p->adj]) {
                ve[p->adj] = ve[i] + p->weight;
            }
        }
    }

    std::vector<int> vl(C, ve[C-1]);
    for (int i = C - 2; i >= 0; --i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            if (vl[p->adj] - p->weight < vl[i]) {
                vl[i] = vl[p->adj] - p->weight;
            }
        }
    }

    for (int i = 0; i < C; ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            int early = ve[i], late = vl[p->adj] - p->weight;
            if (early == late) {
                std::cout << g->vex(i) << " -> "
                    << g->vex(p->adj) << '\n';
            }
        }
    }
}
