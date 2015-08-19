#include "common/matrix2.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

matrix_t add(
        const matrix_t & ma, int * va, int alen,
        const matrix_t & mb, int * vb, int blen)
{
    matrix_t mc(ma.row(), ma.col());
    int ia = -1, ib = -1;
    for (int r = 0; r < ma.row(); ++r) {
        for (int c = 0; c < ma.col(); ++c) {
            mc[r][c] = 0;
            int na = ma[r][c], nb = mb[r][c];
            if (na) {
                ++ia;
                mc[r][c] += va[ia];
            }
            if (nb) {
                ++ib;
                mc[r][c] += vb[ib];
            }
        }
    }
    return mc;
}
