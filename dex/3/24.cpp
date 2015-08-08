// @mission: 参见24.png

int g(int m, int n);
int g2(int m, int n);

#include <iostream>

int main()
{
    int m = 0, n = 0;
    std::cin >> m >> n;

    int r1 = g(m,n);
    int r2 = g(m,n);

    std::cout << r1 << ',' << r2 << '\n';

    return 0;
}
