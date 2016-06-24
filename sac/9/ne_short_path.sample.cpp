#include <vector>
#include <queue>
#include <stack>
#include "ne_short_path.def.h"

typedef typename list_t::node arc_t;

void negative_weight_shortest_path(graph_t * g, char s)
{
    int N = g->vex_count();
    int si = g->id(s);
    list_t * L = g->get_structure();

    std::vector<int> dist(N, g->unconnected_value());
    std::vector<int> prev(N, -1);
    std::vector<int> inq(N, 0);
    std::vector<int> inq_c(N, 0);
    std::queue<int> qu;

    int UNL = g->unconnected_value();
    qu.push(si);
    inq[si] = 1;
    ++inq_c[si];
    dist[si] = 0;

    bool enqueue_limit = false;

    while (!qu.empty() && !enqueue_limit) {
        int t = qu.front();
        qu.pop();
        inq[t] = 0;
        for (arc_t * p = L->_heads[t]; p; p = p->next) {
            if (dist[t] < UNL && dist[t] + p->weight < dist[p->adj]) {
                dist[p->adj] = dist[t] + p->weight;
                prev[p->adj] = t;
                if (!inq[p->adj]) {
                    qu.push(p->adj);
                    inq[p->adj] = 1;
                    ++inq_c[p->adj];
                    if (inq_c[p->adj] > N) {
                        enqueue_limit = true;
                    }
                }
            }
        }
    }

    std::stack<char> stk;
    for (int i = 0; i < N; ++i) {
        if (i != si) {
            int j = i;
            do {
                stk.push(g->vex(j));
                j = prev[j];
            } while (j != -1 && j != i);

            while (!stk.empty()) {
                std::cout << stk.top() << ' ';
                stk.pop();
            }
            std::cout << '\n';
        }
    }
}
