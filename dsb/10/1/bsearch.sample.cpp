#include "bsearch.def.h"

bool b_search(const int * arr, int len, int k)
{
    int low = 0, high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            return true;
        } else if (k < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}
