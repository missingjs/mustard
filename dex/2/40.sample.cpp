#include "def.h"
using namespace mustard::dex_2;

typedef sq_poly<int,int> poly_t;
typedef poly_term<int,int> term_t;

poly_t * subtract(poly_t * p1, poly_t * p2)
{
    if (p1 == NULL || p2 == NULL) {
        return NULL;
    }

    term_t * data = new term_t[p1->last + p2->last];
    int t = 0;

    int i = 0, j = 0;
    while (i < p1->last && j < p2->last) {
        if (p1->data[i].exp > p2->data[j].exp) {
            data[t++] = p1->data[i++];
        } else if (p1->data[i].exp < p2->data[j].exp) {
            data[t].coef = -(p2->data[j].coef);
            data[t].exp = p2->data[j].exp;
            ++t;
            ++j;
        } else {
            int coef = p1->data[i].coef - p2->data[j].coef;
            if (coef != 0) {
                data[t].coef = coef;
                data[t].exp = p1->data[i].exp;
                ++t;
            }
            ++i;
            ++j;
        }
    }

    while (i < p1->last) {
        data[t++] = p1->data[i++];
    }

    while (j < p2->last) {
        data[t].coef = -(p2->data[j].coef);
        data[t].exp = p2->data[j].exp;
        ++t;
        ++j;
    }

    sq_poly<int,int> * poly = new sq_poly<int,int>();
    poly->data = data;
    poly->last = t;

    return poly;
}
