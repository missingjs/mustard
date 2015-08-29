#include "11.def.h"
#include <stack>
#include <cstring>

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
/*
void dfs(graph_t * g, char start)
{
    arc_t * p = NULL;
    std::stack<arc_t*> stk;

    int * visited = new int[g->vex_count()];
    memset(visited, 0, sizeof(int) * g->vex_count());

    std::cout << start << ' ';
    int k = g->id(start);
    visited[k] = 1;

    adj_list_t * a_list = g->get_structure();
    stk.push(a_list->_heads[k]);

    while (!stk.empty()) {
        arc_t * & p = stk.top();
        if (!p) {
            stk.pop();
        }
        while (p) {
            int i = p->adj;
            if (!visited[i]) {
                std::cout << g->vex(i) << ' ';
                visited[i] = 1;
                stk.push(a_list->_heads[i]);
                break;
            }
            p = p->next;
        }
    }

    std::cout << '\n';

    delete[] visited;
}
*/
