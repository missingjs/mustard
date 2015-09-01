#include "10.def.h"

char get_root(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return 0;
    }

    int C = g->vex_count();
    mx_t mx(*g->get_structure());
    mx_t M(mx);

    for (int i = 0; i < C; ++i) {
        M[i][i] = true;
    }

    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!M[i][j] && M[i][k] && M[k][j]) {
                    M[i][j] = true;
                }
            }
        }
    }

    matrix::print(M);

    int r = -1;
    for (int i = 0; i < C; ++i) {
        int j = 0;
        for (; j < C; ++j) {
            if (!M[i][j]) {
                break;
            }
        }
        if (j == C) {
            r = i;
            break;
        }
    }

    return (r >= 0) ? g->vex(r) : '#';
}
