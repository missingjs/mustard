#include "32.def.h"
#include <vector>
#include <list>

namespace {

    std::vector<tree_t*> nodes;  // tree node for each vex

    int _unlimit = graph::numeric_weight<int>::unconnected_value();

}

struct _prim
{
    int v, u;
    int weight;
    _prim(int v=0, int u=0, int w=0)
        : v(v), u(u), weight(w)
    {}
};

typedef typename std::list<_prim>::iterator it_t;

it_t _find_min(std::list<_prim> & costs)
{
    if (costs.size() == 1) {
        return costs.begin();
    }

    it_t min = costs.begin(), it = costs.begin();
    for (++it; it != costs.end(); ++it) {
        if (it->weight < min->weight) {
            min = it;
        }
    }

    return min;
}

void _build_mst(graph_t * g, const mx_t & mx, int i)
{
    int C = g->vex_count();
    std::list<_prim> costs;
    for (int j = 0; j < C; ++j) {
        if (i != j) {
            costs.push_back(_prim(i,j,mx[i][j]));
        }
    }
    nodes[i] = new tree_t(g->vex(i));

    while (costs.size()) {
        it_t min = _find_min(costs);
        if (min->weight == _unlimit) {
            break;
        }
        _prim pr = *min;
        costs.erase(min);
        for (it_t it = costs.begin(); it != costs.end(); ++it) {
            int u = pr.u;
            int w = mx[u][it->u];
            if (w < it->weight) {
                it->weight = w;
                it->v = u;
            }
        }

        tree_t * node = new tree_t(g->vex(pr.u));
        nodes[pr.u] = node;
        tree_t * parent = nodes[pr.v];
        if (!parent->lc) {
            parent->lc = node;
        } else {
            tree_t * p = parent->lc;
            while (p->rc) {
                p = p->rc;
            }
            p->rc = node;
        }
    }
}

tree_t * prim_mst_forest(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return NULL;
    }

    int C = g->vex_count();
    mx_t & mx = *g->get_structure();

    nodes.assign(C, NULL);
    tree_t *root = NULL, *most_right = NULL;

    for (int i = 0; i < C; ++i) {
        if (!nodes[i]) {
            _build_mst(g, mx, i);
            if (nodes[i]) {
                if (!root) {
                    most_right = root = nodes[i];
                } else {
                    most_right->rc = nodes[i];
                    most_right = nodes[i];
                }
            }
        }
    }

    return root;
}
