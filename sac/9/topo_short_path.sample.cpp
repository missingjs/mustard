#include <vector>
#include <queue>
#include <stack>
#include "topo_short_path.def.h"

typedef typename list_t::node arc_t;

void get_indegree(list_t * L, std::vector<int> & indeg)
{
    int N = indeg.size();
    for (int i = 0; i < N; ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            ++indeg[p->adj];
        }
    }
}

void topo_shortest_path(graph_t * g, char s)
{
    list_t * L = g->get_structure();
    int N = g->vex_count();
    int si = g->id(s);

    std::vector<int> indeg(N, 0);
    get_indegree(L, indeg);

    std::queue<int> qu;
    for (int i = 0; i < N; ++i) {
        if (indeg[i] == 0) {
            qu.push(i);
        }
    }

    std::queue<int> q2;

    while (!qu.empty()) {
        int t = qu.front();
        q2.push(t);
        qu.pop();
        for (arc_t * p = L->_heads[t]; p; p = p->next) {
            --indeg[p->adj];
            if (indeg[p->adj] == 0) {
                qu.push(p->adj);
            }
        }
    }

    int UNL = g->unconnected_value();
    std::vector<int> dist(N, UNL);
    std::vector<int> prev(N, -1);
    dist[si] = 0;
    while (!q2.empty()) {
        int t = q2.front();
        q2.pop();
        for (arc_t * p = L->_heads[t]; p; p = p->next) {
            if (dist[t] + p->weight < dist[p->adj]) {
                dist[p->adj] = dist[t] + p->weight;
                prev[p->adj] = t;
            }
        }
    }

    std::stack<char> stk;
    for (int i = 0; i < N; ++i) {
        if (i != si) {
            int j = i;
            while (j != -1) {
                stk.push(g->vex(j));
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
