#include <cstddef>
#include <cstdlib>
#include <iostream>

int solution_count = 0;

void pq(int * cols, int n, int k)
{
    if (k == n) {
        ++solution_count;
        std::cout << '[' << solution_count << "] ";
        for (int i = 0; i < n; ++i) {
            std::cout << '(' << i << ',' << cols[i] << ") ";
        }
        std::cout << '\n';
        return;
    }

    for (int i = 0; i < n; ++i) {
        int row = k, col = i;
        int j = 0;
        for (; j < k; ++j) {
            int r = j, c = cols[j];
            if (col == c) {
                break;
            } else if (abs(row-r) == abs(col-c)) {
                break;
            }
        }
        if (j == k) {
            cols[k] = i;
            pq(cols, n, k + 1);
        }
    }
}

void print_queens(int n)
{
    if (n <= 0) {
        return;
    }

    int * cols = new int[n];

    pq(cols, n, 0);

    delete[] cols;
}
