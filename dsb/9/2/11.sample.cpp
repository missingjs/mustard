#include "11.def.h"
#include <stack>

typedef typename adj_list_t::node arc_t;

struct st
{
    int id;
    arc_t * arc;
    st(int id)
        : id(id), arc(NULL)
    {}
};

void dfs(graph_t * g, char start)
{
    if (!g || g->id(start) < 0) {
        return;
    }

    std::stack<st> stk;
    stk.push(st(g->id(start)));

    adj_list_t * ad_list = g->get_structure();
    int * visited = new int[g->vex_count()];
    for (int i = 0; i < g->vex_count(); ++i) {
        visited[i] = 0;
    }

    while (!stk.empty()) {
        st & t = stk.top();
        if (!visited[t.id]) {
            std::cout << g->vex(t.id) << ' ';
            visited[t.id] = 1;
            t.arc = ad_list->_heads[t.id];
        } else if (!t.arc) {
            stk.pop();
        } else {
            arc_t * a = t.arc;
            t.arc = a->next;
            if (!visited[a->adj]) {
                stk.push(st(a->adj));
            }
        }
    }

    std::cout << '\n';
    delete[] visited;
}
