// @brief: 采用39题给定的条件和存储结构，求两个多项式相减，将结果存放在新辟空间中

#include "def.h"
using namespace mustard::dex_2;

typedef sq_poly<int,int> poly_t;

poly_t * subtract(poly_t * p1, poly_t * p2);

int main()
{
    poly_t * p1 = read_poly<int,int>();
    poly_t * p2 = read_poly<int,int>();

    poly_t * p3 = subtract(p1, p2);

    p3->print();

    free_poly(p1);
    free_poly(p2);
    free_poly(p3);

    return 0;
}
