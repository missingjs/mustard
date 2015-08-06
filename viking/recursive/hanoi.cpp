// @mission: 分别以递归和非递归形式解决梵塔问题

#include <iostream>

void hanoi(int n);

void hanoi_2(int n);

int main()
{
    int n = 0;
    std::cin >> n;

    hanoi(n);
    std::cout << "-----------------\n";
    hanoi_2(n);

    return 0;
}
