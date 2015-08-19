#include "common/matrix2.h"
#include <vector>
using namespace mustard;

typedef matrix::common_matrix<int> matrix_t;

struct cell
{
    int coef;
    int x;
    int y;
    cell(int coef, int x, int y)
        : coef(coef), x(x), y(y)
    {}
};

void print_cell(const cell & c)
{
    if (c.coef > 1 || c.coef < -1) {
        std::cout << c.coef;
    } else if (c.coef == -1) {
        std::cout << '-';
    }

    if (c.x == 1) {
        std::cout << 'x';
    } else if (c.x != 0) {
        std::cout << "xE" << c.x;
    }

    if (c.y == 1) {
        std::cout << 'y';
    } else if (c.y != 0) {
        std::cout << "yE" << c.y;
    }
}

void dump(const std::vector<cell> & cells)
{
    print_cell(cells[0]);

    for (size_t i = 1; i < cells.size(); ++i) {
        if (cells[i].coef > 0) {
            std::cout << '+';
        }
        print_cell(cells[i]);
    }
    std::cout << '\n';
}

void print_polynomial(const matrix_t & m)
{
    std::vector<cell> cells;
    for (int i = m.row() - 1; i >= 0; --i) {
        int r = i, c = 0;
        for (; r >= 0; --r, ++c) {
            if (m[r][c] != 0) {
                cells.push_back(cell(m[r][c], r, c));
            }
        }
    }

    dump(cells);
}
