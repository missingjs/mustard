#include "31.def.h"
#include <vector>
#include <stack>
#include <algorithm>

namespace { 
    
    int _count = 0; 

    std::vector<int> _processed, _visited;

}

void _dfs(graph_t * g, list_t * L,
        int v, std::vector<int> & low,
        std::vector<int> & dfn,
        std::stack<int> & stk,
        std::vector<int> & in_stack)
{
    low[v] = dfn[v] = ++_count;
    in_stack[v] = 1;
    stk.push(v);
    _visited[v] = 1;

    for (arc_t * p = L->_heads[v]; p; p = p->next) {
        if (_processed[p->adj]) {
            continue;
        }
        if (!in_stack[p->adj]) {
            _dfs(g,L,p->adj,low,dfn,stk,in_stack);
            low[v] = std::min(low[v], low[p->adj]);
        } else {
            low[v] = std::min(low[v], dfn[p->adj]);
        }
    }

    if (low[v] == dfn[v]) {
        int t;
        do {
            t = stk.top();
            in_stack[t] = 0;
            stk.pop();
            std::cout << g->vex(t) << ' ';
            _processed[t] = 1;
        } while (t != v);
        std::cout << '\n';
    }
}

void get_scc(graph_t * g)
{
    if (!g || !g->vex_count()) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();
    _processed.assign(C, 0);
    _visited.assign(C, 0);

    std::stack<int> stk;
    std::vector<int> in_stack(C, 0), low(C, 0), dfn(C, 0);

    for (int i = C - 1; i >= 0; --i) {
        if (!_visited[i]) {
            _dfs(g, L, i, low, dfn, stk, in_stack);
        }
    }
}
