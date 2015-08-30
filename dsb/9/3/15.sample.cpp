#include "15.def.h"
#include <algorithm>
#include <vector>

struct _edge
{
    int a, b;
    int weight;

    _edge(int a, int b, int weight)
        : a(a), b(b), weight(weight)
    {}

    struct _cmp
    {
        bool operator()(const _edge & e1, const _edge & e2)
        {
            return e1.weight < e2.weight;
        }
    };
};

int _get_parent(int * group, int i)
{
    int p = i;
    while (group[p] >= 0) {
        p = group[p];
    }

    if (p == i) {
        return i;
    }

    int k = i, t = 0;
    while (group[k] != p) {
        t = k;
        k = group[k];
        group[t] = p;
    }

    return p;
}

void _merge(int * group, int a, int b)
{
    if (group[a] < group[b]) {
        group[a] += group[b];
        group[b] = a;
    } else {
        group[b] += group[a];
        group[a] = b;
    }
}

void kruskal_print_edge(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();
    
    std::vector<_edge> edges;
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        while (p) {
            if (p->adj > 0) {
                edges.push_back(_edge(i,p->adj,p->weight));
            }
            p = p->next;
        }
    }

    std::sort(edges.begin(), edges.end(), _edge::_cmp());

    int * group = new int[C];
    for (int i = 0; i < C; ++i) {
        group[i] = -1;
    }

    int n = 0;
    for (size_t i = 0; i < (int) edges.size() && n < C - 1; ++i) {
        _edge & e = edges[i];
        int pa = _get_parent(group, e.a);
        int pb = _get_parent(group, e.b);
        if (pa < 0 && pb < 0 || pa != pb) {
            ++n;
            std::cout << '[' <<  g->vex(e.a) << ' ' 
                << g->vex(e.b) << ' ' << e.weight << "]\n";
            _merge(group, pa, pb);
        }
    }

    if (n < C - 1) {
        std::cout << "no a connected graph!\n";
    }
}
