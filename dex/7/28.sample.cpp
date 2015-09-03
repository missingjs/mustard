#include "28.def.h"
#include <vector>

void _dfs(graph_t * g, list_t * L, int i,
        std::vector<int> & visited,
        std::vector<int> & path)
{
    if (i == g->id('v')) {
        for (auto k = path.begin(); k != path.end(); ++k) {
            std::cout << g->vex(*k) << ' ';
        }
        std::cout << 'v' << '\n';
        return;
    }

    visited[i] = 1;
    path.push_back(i);

    arc_t * p = L->_heads[i];
    for (; p; p = p->next) {
        if (!visited[p->adj]) {
            _dfs(g, L, p->adj, visited, path);
        }
    }

    visited[i] = 0;
    path.pop_back();
}

void find_all_path(graph_t * g)
{
    if (!g || g->id('v') < 0 || g->id('u') < 0) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> visited(C, 0), path;
    int start = g->id('u');
    _dfs(g, L, start, visited, path);
}
