#include <stack>
#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

struct mz
{
    int r, c;
    int dir;

    mz(int r, int c)
        : r(r), c(c), dir(0)
    {}
};

void print_path(matrix_t * m, int start_row, int start_col)
{
    if (m == NULL || start_row < 0 || start_row >= m->row || start_col < 0 || start_col >= m->col || m->get(start_row, start_col) != 0) {
        return;
    }

    std::stack<mz> stk;
    stk.push(mz(start_row, start_col));

    while (!stk.empty()) {
        mz & top = stk.top();
        if (top.dir > 3) {
            stk.pop();
            continue;
        }
        int n_r = 0, n_c = 0;
        switch (top.dir) {
            case 0:
                n_r = top.r - 1;
                n_c = top.c;
                break;
            case 1:
                n_r = top.r;
                n_c = top.c + 1;
                break;
            case 2:
                n_r = top.r + 1;
                n_c = top.c;
                break;
            case 3:
                n_r = top.r;
                n_c = top.c - 1;
                break;
        }
    }
}
