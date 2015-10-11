// @mission: 参见7.png
#include <cstddef>
#include "poly.h"
#include "7.def.h"


int main()
{
    poly_t * p1 = read_exp_list();
    print_exp_list(p1);
    poly_t * p2 = read_exp_list();
    print_exp_list(p2);

    poly_t * pa = multiply_a(p1, p2);
    print_exp_list(pa);

    poly_t * pb = multiply_b(p1, p2);
    print_exp_list(pb);

    poly_t * pc = multiply_c(p1, p2);
    print_exp_list(pc);

    free_exp_list(pa);
    free_exp_list(pb);
    free_exp_list(pc);
    return 0;
}
