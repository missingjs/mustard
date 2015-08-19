#include "common/matrix2.h"
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

void print_saddle_points(const matrix_t & m)
{
    for (int i = 0; i < m.row(); ++i) {
        int min_value = m[i][0], min_j = 0;
        for (int j = 1; j < m.col(); ++j) {
            if (m[i][j] < min_value) {
                min_value = m[i][j];
                min_j = j;
            }
        }
        int r = 0;
        for (; r < m.row() && m[r][min_j] <= min_value; ++r)
            ;;
        if (r == m.row()) {
            std::cout << i << ',' << min_j << ',' << m[i][min_j] << '\n';
        }
    }
}
