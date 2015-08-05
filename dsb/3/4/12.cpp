// @brief: 参见12.png

#include <iostream>

// recursive
int akm_1(int m, int n);

// non-recursive
int akm_2(int m, int n);

int main()
{
    int m = 0, n = 0;
    std::cin >> m >> n;

    int a1 = akm_1(m,n);
    int a2 = akm_2(m,n);

    std::cout << a1 << ',' << a2 << std::endl;

    return 0;
}
