#include <iostream>
#include "common/array.h"
using namespace mustard;

int * intersection_1(const int * a, int len_a, const int * b, int len_b, int & len_c);
int * intersection_override(int * a, int len_a, const int * b, int len_b, int & len_c);

int main()
{
    int *a = NULL, len_a = 0;
    a = array_n_read<int>(len_a);

    int *b = NULL, len_b = 0;
    b = array_n_read<int>(len_b);

    int *c = NULL, len_c = 0;
    c = intersection_override(a, len_a, b, len_b, len_c);

    array_print(c, len_c);

    array_free(a);
    array_free(b);

    if (c != a && c != b) {
        array_free(c);
    }

    return 0;
}

int * intersection_override(int * a, int len_a, const int * b, int len_b, int & len_c)
{
    if (a == NULL || len_a < 0 || b == NULL || len_b < 0) {
        len_c = 0;
        return a;
    }

    int ai = 0, aj = 0;
    while (aj < len_a) {
        int bi = 0;
        for (; bi < len_b && a[aj] != b[bi]; ++bi)
            ;
        if (bi < len_b) {
            if (ai != aj) {
                a[ai] = a[aj];
            }
            ++ai;
        }
        ++aj;
    }

    len_c = ai;

    return a;
}

int * intersection_1(const int * a, int len_a, const int * b, int len_b, int & len_c)
{
    if (a == NULL || len_a < 0 || b == NULL || len_b < 0) {
        len_c = 0;
        return NULL;
    }

    int L = len_a > len_b ? len_b : len_a;
    int * c = new int[L];

    int k = 0;
    for (int i = 0; i < len_a; ++i) {
        int j = 0;
        for (; j < len_b; ++j) {
            if (a[i] == b[j]) {
                break;
            }
        }
        if (j < len_b) {
            c[k] = a[i];
            ++k;
        }
    }

    len_c = k;

    return c;
}

