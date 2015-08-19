// @mission: 参见20.png

#include "common/matrix2.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

void print_polynomial(const matrix_t & m);

int main()
{
    matrix_t * m = matrix::read_common_matrix<int>();
    print_polynomial(*m);
    delete m;
    return 0;
}
