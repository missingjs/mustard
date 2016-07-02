// @mission: Calculate matrix multiplying sequence.
#include <iostream>
#include "mx_mult.def.h"

int main()
{
    int N = 0;
    std::cin >> N;

    char * m = new char[N];
    int * rows = new int [N];
    int * cols = new int[N];

    for (int i = 0; i < N; ++i) {
        std::cin >> m[i] >> rows[i] >> cols[i];
    }

    optimal_matrix_multiply(N,m,rows,cols);

    delete[] m;
    delete[] rows;
    delete[] cols;
    return 0;
}

