// @mission: 实现折半查找
#include "bsearch.def.h"

int main()
{
    int len = 0;
    int * arr = array::read<int>(len);

    int k = 0;
    std::cin >> k;

    bool r = b_search(arr, len, k);
    std::cout << std::boolalpha << r << '\n';

    delete[] arr;
    return 0;
}
