#include <iostream>
#include <limits>
#include <vector>

#include "opt_tree.def.h"

void optimal_search_tree(int N, const std::vector<std::string> & words, const std::vector<double> & p)
{
    mx_t cost(N,N), pn(N,N);
    double MAX = std::numeric_limits<double>::max();

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cost[i][j] = MAX;
            pn[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        cost[i][i] = pn[i][i] = p[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            cost[i][j] = pn[i][j] = 0;
        }
    }

    for (int k = 1; k < N; ++k) {
        for (int left = 0; left < N - k; ++left) {
            int right = left + k;
            pn[left][right] = pn[left][right-1] + p[right];
            for (int i = left; i <= right; ++i) {
                double c = pn[left][right] + cost[left][i-1] + cost[i+1][right];
                if (c < cost[left][right]) {
                    cost[left][right] = c;
                }
            }
        }
    }

    std::cout << "min cost: " << cost[0][N-1] << '\n';
}
