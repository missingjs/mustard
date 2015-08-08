// @mission: from 25.png

#include <iostream>

int F(int n);
int F2(int n);

int main()
{
    int n = 0;
    std::cin >> n;

    int f1 = F(n);
    int f2 = F2(n);

    std::cout << f1 << ',' << f2 << '\n';

    return 0;
}
