#include "30.def.h"
#include <vector>
#include <algorithm>
#include <stack>

std::vector<int> _get_indegree(list_t * L, int C)
{
    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        arc_t * p = L->_heads[i];
        for (; p; p = p->next) {
            ++indeg[p->adj];
        }
    }
    return indeg;
}

namespace {
std::vector<int> _low, _dfn;
std::vector<int> _visited;   // if in stack
std::stack<int> _stk;
std::vector<int> _scc;    // belong to a existed SCC
int _count = 0;
}

void _dfs(graph_t * g, list_t * L, int v, std::stack<int> & path, 
        std::vector<int> & in_path)
{
    if (!_visited[v]) {
        _low[v] = _dfn[v] = ++_count;
        _stk.push(v);
        _visited[v] = 1;
    }

    path.push(v);
    in_path[v] = 1;

    arc_t * p = L->_heads[v];
    for (; p; p = p->next) {
        int a = p->adj;
        if (_scc[a]) {
            continue;
        }

        if (!in_path[a]) {
            _dfs(g, L, a, path, in_path);
            _low[v] = std::min(_low[v], _low[a]);
        } else {
            _low[v] = std::min(_low[v], _dfn[a]);
            std::stack<int> tmp;
            int t;
            do {
                t = path.top();
                tmp.push(t);
                path.pop();
            } while (t != a);
            while (!tmp.empty()) {
                std::cout << g->vex(tmp.top()) << ' ';
                path.push(tmp.top());
                tmp.pop();
            }
            std::cout << '\n';
        }
    }

    if (_low[v] == _dfn[v] && !_scc[v]) {
        int t;
        do {
            t = _stk.top();
            _stk.pop();
            _scc[t] = 1;
        } while (t != v);
    }

    path.pop();
    in_path[v] = 0;
}

void print_all_simple_loop(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    _low.assign(C,0);
    _dfn.assign(C,0);
    _visited.assign(C,0);
    _scc.assign(C,0);

    std::stack<int> path;
    std::vector<int> in_path(C, 0);
    std::vector<int> indeg = _get_indegree(L, C);
    bool go = false;
    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            go = true;
            _dfs(g, L, i, path, in_path);
        }
    }

    if (!go) {
        _dfs(g, L, 0, path, in_path);
    }
}
