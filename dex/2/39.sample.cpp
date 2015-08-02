#include <cmath>
#include "def.h"
using namespace mustard::dex_2;

typedef poly_term<int,int> term_t;

int evaluate(sq_poly<int,int> * poly, int x)
{
    if (poly == NULL || poly->last == 0) {
        return 0;
    }

    term_t * p = poly->data;
    int r = 0;
    for (int i = 0; i < poly->last; ++i) {
        int c = poly->data[i].coef, e = poly->data[i].exp;
        r += (int)(c * std::pow(x,e));
    }

    return r;
}
