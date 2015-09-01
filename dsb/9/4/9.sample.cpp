#include "9.def.h"

char get_center_point(graph_t * g)
{
    if (!g || g->vex_count() < 1) {
        return 0;
    }

    int C = g->vex_count();
    mx_t & mx = *g->get_structure();
    mx_t M(mx);

    int MAX = graph::numeric_weight<int>::unconnected_value();

    for (int k = 0; k < C; ++k) {
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < C; ++j) {
                if (i == j || k == i || k == j) {
                    continue;
                }

                int ik = M[i][k], kj = M[k][j];
                if (ik < MAX && kj < MAX && ik + kj < M[i][j]) {
                    M[i][j] = ik + kj;
                }
            }
        }
    }

    int p = MAX, ip = -1;
    for (int i = 0; i < C; ++i) {
        int m = 0;
        for (int j = 0; j < C; ++j) {
            if (M[j][i] < MAX && M[j][i] > m) {
                m = M[j][i];
            }
        }
        std::cout << "m: " << m << '\n';
        if (m < p) {
            p = m;
            ip = i;
        }
    }

    return g->vex(ip);
}
