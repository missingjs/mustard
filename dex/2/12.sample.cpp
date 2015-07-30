#include <stddef.h>

int compare(const int * a, int len_a, const int * b, int len_b)
{
    if (a == NULL || len_a <= 0) {
        if (b == NULL || len_b <= 0) {
            return 0;
        } else {
            return -1;
        }
    } else if (b == NULL || len_b <= 0) {
        return 1;
    }

    int ai = 0, bi = 0;
    for (; ai < len_a && bi < len_b && a[ai] == b[bi]; ++ai, ++bi)
        ;;

    if (ai == len_a) {
        if (bi == len_b) {
            return 0;
        } else {
            return -1;
        }
    } else if (bi == len_b) {
        return 1;
    }

    if (a[ai] > b[bi]) {
        return 1;
    } else {
        return -1;
    }
}
