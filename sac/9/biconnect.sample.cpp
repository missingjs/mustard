#include <vector>
#include <iostream>
#include "biconnect.def.h"

typedef typename list_t::node arc_t;

void _dfs(graph_t * g, list_t * L, int parent, int s, int & counter, std::vector<int> & num, std::vector<int> & low)
{
    num[s] = low[s] = counter;
    ++counter;

    for (arc_t * p = L->_heads[s]; p; p = p->next) {
        if (num[p->adj] == 0) {
            _dfs(g, L, s, p->adj, counter, num, low);
            int w = low[p->adj];
            if (w >= num[s]) {
                std::cout << "articulation point: " << g->vex(s) << std::endl;
            }
            if (w < low[s]) {
                low[s] = low[p->adj];
            }
        } else if (p->adj != parent) {
            if (num[p->adj] < low[s]) {
                low[s] = num[p->adj];
            }
        }
    }
}

void print_articulation_points(graph_t * g)
{
    int N = g->vex_count();
    std::vector<int> num(N), low(N);
    int counter = 1;
    
    list_t * S = g->get_structure();
    num[0] = low[0] = counter;
    ++counter;
    int branch = 0;
    for (arc_t * p = S->_heads[0]; p; p = p->next) {
        if (num[p->adj] == 0) {
            _dfs(g, S, 0, p->adj, counter, num, low);
            ++branch;
        }
    }
    if (branch > 1) {
        std::cout << "articulation point (root): " << g->vex(0) << std::endl;
    }
}

