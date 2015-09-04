#include "35.def.h"

void find_root(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return;
    }

    int C = g->vex_count();
    mx_t mx(*g->get_structure());

    for (int i = 0; i < C; ++i) {
        mx[i][i] = true;
    }

    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!mx[i][j] && mx[i][k] && mx[k][j]) {
                    mx[i][j] = true;
                }
            }
        }
    }

    for (int r = 0; r < C; ++r) {
        int c = 0;
        for (; c < C; ++c) {
            if (!mx[r][c]) {
                break;
            }
        }
        if (c == C) {
            std::cout << g->vex(r) << ' ';
        }
    }
    std::cout << '\n';
}
