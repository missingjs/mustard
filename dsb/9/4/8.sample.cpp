#include "8.def.h"
#include <vector>

void print_MST(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    int MAX = graph::numeric_weight<int>::unconnected_value();
    mx_t & mx = *g->get_structure();

    std::vector<int> dist(C, MAX), path(C, -1), mark(C, 0);
    mark[0] = 1;

    for (int i = 1; i < C; ++i) {
        dist[i] = mx[0][i];
        if (dist[i] < MAX) {
            path[i] = 0;
        }
    }

    for (int n = C - 1; n > 0; --n) {
        int min_v = MAX, min_i = -1;
        for (int i = 1; i < C; ++i) {
            if (mark[i]) {
                continue;
            } else if (dist[i] < min_v) {
                min_v = dist[i];
                min_i = i;
            }
        }
        if (min_i == -1) {
            for (int k = 0; k < C; ++k) {
                if (dist[k] == MAX) {
                    std::cout << '*';
                } else {
                    std::cout << dist[k];
                }
                std::cout << ' ';
            }
            std::cout << '\n';
            for (int k = 0; k < C; ++k) {
                std::cout << mark[k] << ' ';
            }
            std::cout << '\n';
            std::cout << "not a connected graph!\n";
            return;
        }

        mark[min_i] = 1;
        for (int i = 1; i < C; ++i) {
            if (!mark[i] && mx[min_i][i] < MAX 
                    && dist[i] > dist[min_i] + mx[min_i][i]) 
            {
                dist[i] = dist[min_i] + mx[min_i][i];
                path[i] = min_i;
            }
        }
    }

    mx_t rec(C,C);
    for (int i = 0; i < C; ++i) {
        int p = i, k = path[i];
        while (k >= 0) {
            rec[k][p] = 1;
            p = k;
            k = path[k];
        }
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            if (rec[i][j]) {
                std::cout << g->vex(i) << ' ' << g->vex(j) << '\n';
            }
        }
    }
}
