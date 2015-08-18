#include "common/matrix2.h"
using namespace mustard;

typedef matrix::sparse_matrix<int> matrix_t;
typedef typename matrix_t::tup tup_t;

matrix_t add(const matrix_t & a, const matrix_t & b)
{
    matrix_t c(a.row(), a.col());

    std::vector<tup_t> ap, bp;
    a.get_elements(ap);
    b.get_elements(bp);

    size_t b_len = bp.size();
    for (size_t i = 0; i < ap.size(); ++i) {
        tup_t & ti = ap[i];
        size_t j = 0;
        for (; j < b_len && (bp[j].r != ti.r || bp[j].c != ti.c); ++j)
            ;;
        if (j == b_len) {
            c[ti.r][ti.c] = ti.d;
        } else {
            tup_t nt(ti);
            nt.d += bp[j].d;
            c[nt.r][nt.c] = nt.d;

            if (j < b_len - 1) {
                nt = bp[j];
                bp[j] = bp[b_len-1];
                bp[b_len-1] = nt;
                --b_len;
            }
        }
    }

    for (size_t j = 0; j < b_len; ++j) {
        tup_t & ti = bp[j];
        c[ti.r][ti.c] = ti.d;
    }

    return c;
}
