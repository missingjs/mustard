#include "29.def.h"
#include <vector>

namespace {
int num_path = 0;
int K = 0;

void _dfs(graph_t * g, const mx_t & mx,
        int v, int e,
        std::vector<int> & visited,
        std::vector<int> & path)
{
    if (v == e) {
        if (path.size() == K) {
            ++num_path;
            for (auto i = path.begin(); i != path.end(); ++i) {
                std::cout << g->vex(*i) << ' ';
            }
            std::cout << g->vex(e) << '\n';
        }
        return;
    }

    visited[v] = 1;
    path.push_back(v);

    for (int col = 0; col < mx.col(); ++col) {
        if (col != v && mx[v][col] && !visited[col]) {
            _dfs(g, mx, col, e, visited, path);
        }
    }

    visited[v] = 0;
    path.pop_back();
}
}

int find_num_of_path(graph_t * g, char i, char j, int k)
{
    if (!g || g->id(i) < 0 || g->id(j) < 0 || k <= 0) {
        std::cout << "param error\n";
        return 0;
    }

    K = k;
    int C = g->vex_count();
    mx_t & mx = *g->get_structure();

    std::vector<int> visited(C, 0), path;
    int start = g->id(i), end = g->id(j);
    _dfs(g, mx, start, end, visited, path);

    return num_path;
}
