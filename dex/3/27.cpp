// @mission: from 27.png

#include <iostream>

int akm(int m, int n);
int akm2(int m, int n);

int main()
{
    int m = 0, n = 0;
    std::cin >> m >> n;

    int r1 = akm(m, n);
    int r2 = akm2(m, n);

    std::cout << r1 << ',' << r2 << '\n';

    return 0;
}
