#include <cstddef>
#include <iostream>

void _perm(char * arr, char * start, int n, int m)
{
    if (m == 0) {
        for (char * p = arr; p != start; ++p) {
            std::cout << *p << ' ';
        }
        std::cout << '\n';
        return;
    }

    _perm(arr, start + 1, n - 1, m - 1);

    for (int i = 1; i < n; ++i) {
        char c = *start;
        *start = *(start + i);
        *(start + i) = c;
        _perm(arr, start + 1, n - 1, m - 1);
        c = *start;
        *start = *(start + i);
        *(start + i) = c;
    }
}

void print_permutation(char * arr, int n, int m)
{
    if (!arr || n <= 0 || m <= 0 || m > n) {
        return;
    }
    _perm(arr, arr, n, m);
}
