#include <iostream>
#include <stack>
#include <vector>
#include "dijk.def.h"

typedef typename list_t::node arc_t;

int find_min(const std::vector<int> & dist, const std::vector<int> & found)
{
    int i = -1;
    int min = 100000;
    for (int j = 0; j < dist.size(); ++j) {
        if (!found[j] && dist[j] < min) {
            i = j;
            min = dist[j];
        }
    }
    return i;
}

void dijk_shortest_path(graph_t * g, char s)
{
    int N = g->vex_count();
    int si = g->id(s);
    list_t * L = g->get_structure();

    int c = 0;
    std::vector<int> dist(N, g->unconnected_value());
    std::vector<int> prev(N, -1);
    std::vector<int> found(N, 0);

    dist[si] = 0;

    while(c < N) {
        int m = find_min(dist, found);
        if (m == -1) {
            std::cerr << "not connected graph\n";
            return;
        }
        ++c;
        found[m] = 1;

        for (arc_t * p = L->_heads[m]; p; p = p->next) {
            if (!found[p->adj] && dist[m] + p->weight < dist[p->adj]) {
                dist[p->adj] = dist[m] + p->weight;
                prev[p->adj] = m;
            }
        }
    }

    std::stack<char> stk;
    for (int i = 0; i < N; ++i) {
        if (i != si) {
            stk.push(g->vex(i));
            int j = i;
            while (prev[j] != -1) {
                stk.push(g->vex(prev[j]));
                j = prev[j];
            }

            while (!stk.empty()) {
                std::cout << stk.top() << ' ';
                stk.pop();
            }
            std::cout << '\n';
        }
    }
}
