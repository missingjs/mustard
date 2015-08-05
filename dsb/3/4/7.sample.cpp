#include <cstddef>

int f_max(const int * arr, int len)
{
    if (len == 1) {
        return *arr;
    }

    int n = f_max(arr + 1, len - 1);
    int a = *arr;
    return a > n ? a : n;
}

int f_max_2(const int * arr, int len)
{
    if (len == 1) {
        return *arr;
    }

    int n = f_max_2(arr, len - 1);
    int x = arr[len-1];
    return n > x ? n : x;
}

bool find_max(const int * arr, int len, int & max)
{
    if (arr == NULL || len <= 0) {
        return false;
    }

    max = f_max_2(arr, len);
    return true;
}
