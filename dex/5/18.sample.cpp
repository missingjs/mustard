#include <cstddef>
#include <iostream>

void _reverse(int * arr, int i, int j)
{
    int temp = 0;
    for (; i < j; ++i, --j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void s1(int * arr, int len, int k)
{
    _reverse(arr, 0, len - 1);
    _reverse(arr, 0, k - 1);
    _reverse(arr, k, len - 1);
}

int next(int i, int k, int len)
{
    return (i + k) % len;
}

void s2(int * arr, int len, int k)
{
    int t1 = 0, t2 = 0;
    int count = 0;

    for (int i = 0; i < len && count < len; ++i) {
        t1 = arr[i];
        for (int p = next(i,k,len); p != i; p = next(p,k,len)) {
            t2 = arr[p];
            arr[p] = t1;
            t1 = t2;
            ++count;
        }
        arr[i] = t1;
        ++count;
    }
}

void shift(int * arr, int len, int k)
{
    if (!arr || len <= 0) {
        return;
    }

    k = k % len;
    if (k < 0) {
        k += len;
    } else if (k == 0) {
        return;
    }
    s2(arr, len, k);
}
