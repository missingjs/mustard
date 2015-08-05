// @brief: 求解N阶皇后问题

#include <iostream>

void print_queens(int n);

int main()
{
    int n = 0;
    std::cin >> n;

    print_queens(n);

    return 0;
}
