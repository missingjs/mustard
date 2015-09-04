#include "42.def.h"
#include <list>
#include <vector>
#include <stack>

struct _dij
{
    int v, w;
    _dij(int v=0, int w=0)
        : v(v), w(w)
    {}
};

typedef typename std::list<_dij>::iterator it_t;

it_t _find_min(std::list<_dij> & cost)
{
    it_t min = cost.begin(), i = cost.begin();
    for (++i; i != cost.end(); ++i) {
        if (i->w < min->w) {
            min = i;
        }
    }
    return min;
}

void all_shortest_path(graph_t * g, char s)
{
    if (!g || g->id(s) < 0 || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> path(C, -1);
    std::list<_dij> cost;

    int MAX = graph::numeric_weight<int>::unconnected_value();

    int si = g->id(s);
    for (int i = 0; i < C; ++i) {
        if (i != si) {
            int w = MAX;
            L->get(si, i, w);
            cost.push_back(_dij(i,w));
            path[i] = si;
        }
    }

    while (!cost.empty()) {
        it_t min = _find_min(cost);
        if (min->w == MAX) {
            break;
        }
        _dij dij = *min;
        cost.erase(min);
        for (it_t i = cost.begin(); i != cost.end(); ++i) {
            int w = MAX;
            L->get(dij.v, i->v, w);
            if (w < MAX && dij.w + w < i->w) {
                i->w = dij.w + w;
                path[i->v] = dij.v;
            }
        }
    }

    std::stack<int> stk;
    for (int i = 0; i < C; ++i) {
        if (i != si && path[i] >= 0) {
            int k = i;
            while (k >= 0) {
                stk.push(k);
                k = path[k];
            }
            while (!stk.empty()) {
                std::cout << g->vex(stk.top()) << ' ';
                stk.pop();
            }
            std::cout << '\n';
        }
    }
}
