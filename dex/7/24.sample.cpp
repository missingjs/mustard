#include "24.def.h"
#include <stack>
#include <vector>

void traverse_non_recursive(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> visited(C, 0);

    int start = 0;
    std::stack<arc_t*> stk;

    // init
    std::cout << g->vex(start) << ' ';
    visited[start] = 1;
    stk.push(L->_heads[start]);

    while (!stk.empty()) {
        arc_t * & p = stk.top();
        if (!p) {
            stk.pop();
        } else if (!visited[p->adj]) {
            std::cout << g->vex(p->adj) << ' ';
            visited[p->adj] = 1;
            int u = p->adj;
            p = p->next;
            stk.push(L->_heads[u]);
        } else {
            p = p->next;
        }
    }

    std::cout << '\n';
}
