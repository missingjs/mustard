#include "27.def.h"
#include <vector>

void _dfs(graph_t * g, list_t * L, int s, int u, int k, int len,
        std::vector<int> & visited,
        std::vector<int> & path)
{
    if (s == u && len == k) {
        for (auto i = path.begin(); i != path.end(); ++i) {
            std::cout << g->vex(*i) << ' ';
        }
        std::cout << g->vex(u) << '\n';
        return;
    }

    visited[s] = 1;
    path.push_back(s);

    arc_t * p = L->_heads[s];
    for (; p; p = p->next) {
        if (!visited[p->adj]) {
            _dfs(g, L, p->adj, u, k, len + 1, visited, path);
        }
    }

    visited[s] = 0;
    path.pop_back();
}

void find_len_of_path(graph_t * g, char a, char b, int k)
{
    if (!g || g->id(a) < 0 || g->id(b) < 0 || k <= 0 || a == b) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> visited(C, 0);
    std::vector<int> path;
    _dfs(g, L, g->id(a), g->id(b), k, 0, visited, path);
}
