#include "22.def.h"

bool is_big_heap(int * arr, int n)
{
    if (!arr || n <= 0) {
        return false;
    }

    int * h = arr - 1;
    for (int i = 1; i <= n; ++i) {
        int L = i * 2;
        int R = L + 1;
        if (L > n) {
            break;
        }
        else if (L <= n && h[L] > h[i]) {
            return false;
        }

        if (R > n) {
            break;
        }
        else if (R <= n && h[R] > h[i]) {
            return false;
        }
    }
    return true;
}
