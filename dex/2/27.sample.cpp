#include <stddef.h>

void intersection(int * a, int La, const int * b, int Lb, int &Lc)
{
    if (a == NULL || La <= 0 || b == NULL || Lb <= 0) {
        Lc = 0;
        return;
    }

    int ci = 0;
    int ai = 0, bi = 0;

    while (ai < La && bi < Lb) {
        if (a[ai] < b[bi]) {
            ++ai;
        } else if (a[ai] > b[bi]) {
            ++bi;
        } else {
            if (ci > 0 && a[ci-1] < a[ai] || ci == 0) {
                a[ci++] = a[ai];
            }
            ++ai;
            ++bi;
        }
    }

    Lc = ci;
}
