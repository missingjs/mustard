#include <vector>
#include <stack>
#include "bic_com.def.h"

typedef typename list_t::node arc_t;

std::vector<int> visited;
std::vector<int> num;
std::vector<int> low;
std::vector<int> parent;
int counter = 0;

struct edge
{
    int a, b;
    edge(int a, int b) : a(a), b(b) {}
};

std::stack<edge> stk;

void _dfs(graph_t * g, list_t * L, int s)
{
    num[s] = low[s] = counter;
    ++counter;
    visited[s] = 1;

    for (arc_t * p = L->_heads[s]; p; p = p->next) {
        if (!visited[p->adj]) {
            stk.push(edge(s,p->adj));
            parent[p->adj] = s;
            _dfs(g, L, p->adj);
            if (low[p->adj] >= num[s]) {
                while (!stk.empty() && (stk.top().a != s || stk.top().b != p->adj)) {
                    std::cout << g->vex(stk.top().a) << "-" << g->vex(stk.top().b) << ' ';
                    stk.pop();
                }
                if (!stk.empty()) {
                    std::cout << g->vex(stk.top().a) << "-" << g->vex(stk.top().b) << '\n';
                    stk.pop();
                }
            } else if (low[p->adj] < low[s]) {
                low[s] = low[p->adj];
            }
        } else if (parent[s] != p->adj) {
            if (num[s] > num[p->adj]) {
//            if (low[s] > num[p->adj]) {
//                std::cout << "push: " << g->vex(s) << "-" << g->vex(p->adj) << "\n";
                stk.push(edge(s,p->adj));
            }
            if (low[s] > num[p->adj]) {
                low[s] = num[p->adj];
            }
        }
    }
}

void print_biconnected_components(graph_t * g)
{
    int N = g->vex_count();
    list_t * L = g->get_structure();
    visited.assign(N, 0);
    num.assign(N, -1);
    low.assign(N, -1);
    parent.assign(N, -1);

    for (int k = 0; k < N; ++k) {
        if (visited[k]) {
            continue;
        }
        visited[k] = 1;
        for (arc_t * p = L->_heads[k]; p; p = p->next) {
            if (!visited[p->adj]) {
                stk.push(edge(k, p->adj));
                parent[p->adj] = k;
                _dfs(g, L, p->adj);
            }
    
            bool found = !stk.empty();
            while (!stk.empty()) {
                std::cout << g->vex(stk.top().a) << "-" << g->vex(stk.top().b) << ' ';
                stk.pop();
            }
            if (found) {
                std::cout << '\n';
            }
        }
    }
}
