// @mission: 参见25.png

#include "common/matrix2.h"
#include "common/array.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

matrix_t add(
        const matrix_t & a, int * va, int alen,
        const matrix_t & b, int * vb, int blen
);

int main()
{
    matrix_t * ma = matrix::read_common_matrix<int>();
    int alen = 0;
    int * va = array::read<int>(alen);

    matrix_t * mb = matrix::read_common_matrix<int>();
    int blen = 0;
    int * vb = array::read<int>(blen);

    matrix_t c = add(*ma, va, alen, *mb, vb, blen);

    matrix::print(c);

    delete ma;
    delete mb;
    array::free(va);
    array::free(vb);

    return 0;
}
