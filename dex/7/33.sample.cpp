#include "33.def.h"
#include <algorithm>
#include <queue>

namespace { 

int _unlimit = graph::numeric_weight<int>::unconnected_value();

}

void GetMinEdge(EdgeSet * s, int & u, int & v)
{
    int n = (int) s->edge_list.size();
    EdgeSet::edge & e = s->edge_list[n-1];
    u = e.i;
    v = e.j;
}

void DelMinEdge(EdgeSet * s)
{
    if (!s->edge_list.empty()) {
        s->edge_list.pop_back();
    }
}

struct _edge_cmp
{
    bool operator()(const EdgeSet::edge & e1, 
            const EdgeSet::edge & e2)
    {
        return e1.w > e2.w;
    }
};

EdgeSet * build_edge_set(graph_t * g)
{
    EdgeSet * s = new EdgeSet;
    int C = g->vex_count();
    mx_t & mx = *g->get_structure();
    for (int i = 1; i < C; ++i) {
        for (int j = 0; j < i; ++j) {
            if (mx[i][j] < _unlimit) {
                s->edge_list.push_back(
                        EdgeSet::edge(i,j,mx[i][j]));
            }
        }
    }
    std::sort(s->edge_list.begin(), s->edge_list.end(), _edge_cmp());
    return s;
}

int _get_parent(std::vector<int> & group, int i)
{
    int p = i;
    while (group[p] >= 0) {
        p = group[p];
    }

    int k = i, t;
    while (k != p) {
        t = k;
        k = group[k];
        group[t] = p;
    }
    return p;
}

void _merge(std::vector<int> & group, int p1, int p2)
{
    group[p1] += group[p2];
    group[p2] = p1;
}

void _append_child(tree_t * parent, tree_t * child)
{
    if (!parent->lc) {
        parent->lc = child;
    } else {
        tree_t * q = parent->lc;
        while (q->rc) {
            q = q->rc;
        }
        q->rc = child;
    }
}

tree_t * _build_tree(graph_t * g, const mx_t & mx)
{
    int C = g->vex_count();
    std::queue<tree_t*> qu;
    tree_t * root = new tree_t(g->vex(0));
    qu.push(root);
    std::vector<int> visited(C, 0);

    while (!qu.empty()) {
        tree_t * f = qu.front();
        qu.pop();
        int i = g->id(f->data);
        visited[i] = 1;
        for (int j = 0; j < C; ++j) {
            if (!visited[j] && mx[i][j] < 0) {
                tree_t * n = new tree_t(g->vex(j));
                _append_child(f, n);
                qu.push(n);
            }
        }
    }

    return root;
}

tree_t * kruskal_tree(graph_t * g, EdgeSet * s)
{
    if (!g || !s || g->vex_count() < 2) {
        return NULL;
    }

    int C = g->vex_count();
    int n = 0;  // edge count
    std::vector<int> group(C, -1);
    mx_t mx = mx_t(*g->get_structure());

    while (n < C - 1) {
        int u, v;
        GetMinEdge(s, u, v);
        DelMinEdge(s);
        int pu = _get_parent(group, u);
        int pv = _get_parent(group, v);
        if (pu == pv) {
            continue;
        }
        if (group[pu] <= group[pv]) {
            _merge(group, pu, pv);
        } else {
            _merge(group, pv, pu);
        }
        ++n;
        mx[u][v] = -mx[u][v];
    }

    return _build_tree(g, mx);
}
