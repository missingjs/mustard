#include <iostream>
#include <vector>

#include "network_flow.def.h"

bool _dfs(const matrix_t & mx, int U, int s, int e, std::vector<int> & visited, std::vector<int> & path, int & flux)
{
    visited[s] = 1;
    if (s == e) {
        path.push_back(e);
        return true;
    }

    for (int c = 0; c < mx.col(); ++c) {
        if (s != c && visited[c] == 0 && mx[s][c] != U) {
            if (_dfs(mx, U, c, e, visited, path, flux)) {
                if (flux == -1 || flux > mx[s][c]) {
                    flux = mx[s][c];
                }
                path.push_back(s);
                return true;
            }
        }
    }
    return false;
}

bool dfs_path(const matrix_t & mx, int U, int begin, int end, std::vector<int> & path, int & flux)
{
    path.clear();
    std::vector<int> visited(mx.col());
    flux = -1;
    return _dfs(mx, U, begin, end, visited, path, flux);
}

void network_flow_process(graph_t * g, int begin, int end)
{
    int N = g->vex_count();
    matrix_t * mx = g->get_structure();
    std::vector<int> vexes;
    for (int i = 0; i < N; ++i) {
        vexes.push_back(g->vex(i));
    }

    graph_t * fg = new graph_t(N, vexes.begin(), vexes.end());
    graph_t * rg = new graph_t(N, vexes.begin(), vexes.end());

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int vi = g->vex(i), vj = g->vex(j);
            if (g->get(vi, vj) != g->unconnected_value()) {
                fg->set(vi, vj, 0);
                rg->set(vi, vj, g->get(vi, vj));
            }
        }
    }

    matrix_t &rx = *(rg->get_structure()), &fx = *(fg->get_structure());
    std::vector<int> path;

    int U = g->unconnected_value();
    int flux = 0;
    while (dfs_path(rx, U, g->id(begin), g->id(end), path, flux)) {
        for (int i = path.size() - 1; i > 0; --i) {
            int a = path[i], b = path[i - 1];
            if (fx[a][b] != U) {
                fx[a][b] += flux;
            } else if (fx[b][a] != U) {
                fx[b][a] -= flux;
            }

            rx[a][b] -= flux;
            if (rx[a][b] == 0) {
                rx[a][b] = U;
            }

            rx[b][a] = flux;
        }
    }

    int max_flux = 0;
    int s = g->id(begin);
    for (int i = 0; i < N; ++i) {
        if (fx[s][i] != U) {
            max_flux += fx[s][i];
        }
    }
    std::cout << "max flux: " << max_flux << std::endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (fx[i][j] != U) {
                std::cout << g->vex(i) << " -> " << g->vex(j) << ": " << fx[i][j] << std::endl;
            }
        }
    }

    fg->display(std::cout);
    rg->display(std::cout);

    delete rg;
    delete fg;
}
