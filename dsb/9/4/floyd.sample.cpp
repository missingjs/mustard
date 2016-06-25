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

    // path: if path[i][j] is connected, path[i][j] is the point after i

    int MAX = graph::numeric_weight<int>::unconnected_value();
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            M[i][j] = mx[i][j];
            if (mx[i][j] < MAX) {
                path[i][j] = j;
            } else {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (i == j || k == i || k == j) {
                    continue;
                }

                int x = M[i][k], y = M[k][j];
                if (x < MAX && y < MAX && x + y < M[i][j]) {
                    path[i][j] = path[i][k];
                    M[i][j] = x + y;
                }
            }
        }
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            if (path[i][j] == -1) {
                continue;
            }

            int u = i;
            while (u != -1) {
                std::cout << g->vex(u) << ' ';
                u = path[u][j];
            }
            std::cout << '\n';
        }
    }

//    std::stack<int> stk;
//    for (int i = 0; i < C; ++i) {
//        for (int j = 0; j < C; ++j) {
//            if (i == j || M[i][j] == MAX) {
//                continue;
//            }
//
//            stk.push(j);
//            int k = path[i][j];
//            while (k >= 0) {
//                stk.push(k);
//                k = path[i][k];
//            }
//            stk.push(i);
//
//            while (!stk.empty()) {
//                std::cout << g->vex(stk.top()) << ' ';
//                stk.pop();
//            }
//            std::cout << '\n';
//        }
//    }
}
