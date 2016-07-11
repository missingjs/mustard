// @mission: 最优二叉查找树
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "opt_tree.def.h"

int main()
{
    int N = 0;
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "Invalid N: " << N << '\n';
        exit(1);
    }

    std::vector<std::string> str_list(N);
    std::vector<double> p(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> str_list[i] >> p[i];
    }

    optimal_search_tree(N, str_list, p);

    return 0;
}
