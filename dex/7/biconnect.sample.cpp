#include "biconnect.def.h"
#include <vector>
#include <stack>
#include <algorithm>

struct _edge
{
    int u, v;
    _edge(int u=0, int v=0)
        : u(u), v(v)
    {}

    bool is_edge(int i, int j) const
    {
        return i == u && j == v || i == v && j == u;
    }
};

std::vector<int> _low, _dfn, _visited;
int _count = 0;
std::stack<_edge> _stk;
std::vector<int> _art;

void _report(graph_t * g, int v, int u)
{
    std::cout << "biconnected component: \n";
    _edge e;
    do {
        e = _stk.top();
        _stk.pop();
        std::cout << '(' << g->vex(e.u) << ','
            << g->vex(e.v) << ')' << '\n';
    } while (!_stk.empty() && !e.is_edge(u,v));
}

void _dfs(graph_t * g, list_t * L, int v)
{
    _low[v] = _dfn[v] = ++_count;
    _visited[v] = 1;

    for (arc_t * p = L->_heads[v]; p; p = p->next) {
        if (!_visited[p->adj]) {
            _stk.push(_edge(v, p->adj));
            _dfs(g, L, p->adj);
            if (_low[p->adj] >= _dfn[v]) {
                std::cout << "articulation point: " 
                    << g->vex(v) << '\n';
                _art[v] = 1;
                _report(g, v, p->adj);
            } else {
                _low[v] = _low[p->adj];
            }
        } else {
            _low[v] = std::min(_low[v], _dfn[p->adj]);
        }
    }
}

void biconnected_component(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    _low.assign(C, 0);
    _dfn.assign(C, 0);
    _visited.assign(C, 0);
    _art.assign(C, 0);

    _low[0] = _dfn[0] = ++_count;
    _visited[0] = 1;

    for (arc_t * p = L->_heads[0]; p; p = p->next) {
        if (!_visited[p->adj]) {
            _stk.push(_edge(0,p->adj));
            _dfs(g, L, p->adj);
            if (_count < C) {
                std::cout << "articulation point (root): " 
                    << g->vex(0) << '\n';
                _art[0] = 1;
                // _report(g, 0, p->adj);
            }
        }
    }

    int a = 0;
    for (int i = 0; i < C; ++i) {
        if (_art[i]) {
            ++a;
        }
    }
    if (!a) {
        std::cout << "biconnected graph\n";
    }
}
