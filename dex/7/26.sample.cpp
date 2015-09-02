#include "26.def.h"
#include "common/utils.h"
#include <vector>
#include <queue>
#include <algorithm>

void print_adj_matrix(graph_t * g)
{
    int C = g->vex_count();
    list_t * L = g->get_structure();
    bool b = false;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            if (L->get(i,j,b)) {
                std::cout << 1 << ' ';
            } else {
                std::cout << 0 << ' ';
            }
        }
        std::cout << '\n';
    }
}

std::vector<int>
_topo_sort(graph_t * g)
{
    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        for (; p; p = p->next) {
            indeg[p->adj]++;
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
        int v = qu.front();
        seq.push_back(v);
        qu.pop();
        arc_t * p = L->_heads[v];
        for (; p; p = p->next) {
            indeg[p->adj]--;
            if (indeg[p->adj] == 0) {
                qu.push(p->adj);
            }
        }
    }
    
    std::reverse(seq.begin(), seq.end());
    return seq;
}

void print_lower_tri_matrix(const std::vector<int> & ts, list_t * L)
{
    bool b = false;
    for (int i = 0; i < (int) ts.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (L->get(ts[i], ts[j], b)) {
                std::cout << 1 << ' ';
            } else {
                std::cout << 0 << ' ';
            }
        }
        std::cout << 0 << '\n';
    }
}

void convert(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    print_adj_matrix(g);

    std::vector<int> topo_seq = _topo_sort(g);

    print_lower_tri_matrix(topo_seq, L); 

    std::cout << "\nnew: ";
    for (int i = 0; i < C; ++i) {
        std::cout << i << ' ';
    }
    std::cout << '\n' << "old: ";
    utils::print_list(topo_seq.begin(), topo_seq.end());
    std::cout << "vex: ";
    for (int i = 0; i < C; ++i) {
        std::cout << g->vex(topo_seq[i]) << ' ';
    }
    std::cout << '\n';
}
