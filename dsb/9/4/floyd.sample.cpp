#include "floyd.def.h"
#include <stack>

void floyd_print_all_path(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    mx_t & mx = *g->get_structure();
    mx_t M(C,C), path(C,C);

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            M[i][j] = mx[i][j];
            path[i][j] = -1;
        }
    }

    int MAX = graph::numeric_weight<int>::unconnected_value();
    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (i == j || k == i || k == j) {
                    continue;
                }

                int x = M[i][k], y = M[k][j];
                if (x < MAX && y < MAX && x + y < M[i][j]) {
                    path[i][j] = k;
                    M[i][j] = x + y;
                }
            }
        }
    }

    std::stack<int> stk;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            if (i == j || M[i][j] == MAX) {
                continue;
            }

            stk.push(j);
            int k = path[i][j];
            while (k >= 0) {
                stk.push(k);
                k = path[i][k];
            }
            stk.push(i);

            while (!stk.empty()) {
                std::cout << g->vex(stk.top()) << ' ';
                stk.pop();
            }
            std::cout << '\n';
        }
    }
}
