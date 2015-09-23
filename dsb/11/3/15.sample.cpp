#include "15.def.h"
#include <stack>

struct _qs
{
    int i, j;
    _qs(int i = -1, int j = -1)
        : i(i), j(j)
    {}
};

int _partition(int * arr, int i, int j)
{
    int k = arr[i];

    while (i < j) {
        while (i < j && arr[j] > k) {
            --j;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= k) {
            ++i;
        }
        arr[j] = arr[i];
    }
    arr[i] = k;
    return i;
}

void non_recursive_qsort(int * arr, int n)
{
    if (!arr || n <= 1) {
        return;
    }

    std::stack<_qs> stk;
    stk.push(_qs(0, n - 1));

    while (!stk.empty()) {
        _qs t = stk.top();
        stk.pop();
        int p = _partition(arr, t.i, t.j);
        if (p - t.i > 1) {
            stk.push(_qs(t.i, p - 1));
        }
        if (t.j - (p + 1) > 1) {
            stk.push(_qs(p + 1, t.j));
        }
    }
}
