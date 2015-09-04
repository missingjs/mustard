#include "36.def.h"

void show_each_longest_path(graph_t * g)
{
    if (!g || g->vex_count() < 2) {
        return;
    }

    int C = g->vex_count();
    mx_t mx(*g->get_structure());

    int unlimit = graph::numeric_weight<int>::unconnected_value();

    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (i != j && k != i && k != j) {
                    int ik = mx[i][k];
                    int kj = mx[k][j];
                    if (ik < unlimit && kj < unlimit) {
                        if (mx[i][j] == unlimit || mx[i][j] < ik + kj) {
                            mx[i][j] = ik + kj;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < C; ++i) {
        int max = 0;
        for (int j = 0; j < C; ++j) {
            if (i != j && mx[i][j] < unlimit && mx[i][j] > max) {
                max = mx[i][j];
            }
        }
        if (max > 0 && max < unlimit) {
            std::cout << g->vex(i) << ": " << max << '\n';
        } else {
            std::cout << g->vex(i) << ": *\n";
        }
    }
}
