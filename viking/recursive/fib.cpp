// @brief: 利用递归实现获取fibonacci数列第N项（从1开始）, 并改写为非递归形式
#include <iostream>

// 递归
int fib(int n);

// 非递归
int fib2(int n);

int main()
{
    int n = 0;
    std::cin >> n;

    int f1 = fib(n);
    int f2 = fib2(n);

    std::cout << f1 << ',' << f2 << std::endl;

    return 0;
}
