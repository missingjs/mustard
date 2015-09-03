#include "30.def.h"
#include <vector>

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

void _dfs(graph_t * g, list_t * L, int v,
        std::vector<int> & visited,
        std::vector<int> & path)
{
    visited[v] = 1;
    path.push_back(v);

    arc_t * p = L->_heads[v];
    for (; p; p = p->next) {
        if (!visited[p->adj]) {
            _dfs(g, L, p->adj, visited, path);
        } else {
            auto it = path.begin();
            for (; it != path.end() && *it != p->adj; ++it)
                ;;
            for (; it != path.end(); ++it) {
                std::cout << g->vex(*it) << ' ';
            }
            std::cout << '\n';
        }
    }

    path.pop_back();
    visited[v] = 0;
}

void print_all_simple_loop(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    std::vector<int> visited(C, 0), path;

    std::vector<int> indeg = _get_indegree(L, C);
    bool go = false;
    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            go = true;
            _dfs(g, L, i, visited, path);
        }
    }

    if (!go) {
        _dfs(g, L, 0, visited, path);
    }
}
