#include "dijkstra.def.h"
#include <vector>
#include <stack>

struct _dj
{
    int v;
    int w;
};

int _find_min(std::vector<_dj> & vect)
{
    int m = 0;
    for (size_t i = 1; i < vect.size(); ++i) {
        if (vect[i].w < vect[m].w) {
            m = i;
        }
    }
    return m;
}

int get_weight(list_t * L, int i, int j)
{
    int w;
    return L->get(i,j,w) ? w : graph::numeric_weight<int>::unconnected_value();
}

void dijkstra_show_all_path(graph_t * g, char start)
{
    if (!g || g->vex_count() <= 1) {
        return;
    }

    int C = g->vex_count();
    int * path = new int[C];
    int limit = graph::numeric_weight<int>::unconnected_value();
    list_t * L = g->get_structure();

    std::vector<_dj> vect;
    vect.reserve(C);
    int s = g->id(start);
    path[s] = -1;
    for (int i = 0; i < C; ++i) {
        if (i != s) {
            _dj dj;
            dj.v = i;
            dj.w = get_weight(L,s,i);
            vect.push_back(dj);
            if (dj.w != limit) {
                path[i] = s;
            } else {
                path[i] = -1;
            }
        }
    }

    while (vect.size() > 0) {
        int m = _find_min(vect);
        if (vect[m].w == limit) {
            break;
        }
        if (m != vect.size() - 1) {
            _dj tmp = vect[m];
            vect[m] = vect[vect.size()-1];
            vect[vect.size()-1] = tmp;
        }
        _dj dj = vect[vect.size()-1];
        vect.pop_back();

        int v = dj.v;
        for (size_t i = 0; i < vect.size(); ++i) {
            int u = vect[i].v;
            int vu = get_weight(L, v, u);
            if (vu < limit && vu + dj.w < vect[i].w) {
                vect[i].w = vu + dj.w;
                path[u] = v;
            }
        }
    }

    std::stack<int> stk;
    for (int i = 0; i < C; ++i) {
        if (i != s) {
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

    delete[] path;
}
