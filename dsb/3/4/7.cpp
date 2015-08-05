// @brief: 递归算法求数组中最大元素
#include "common/array.h"
using namespace mustard;

bool find_max(const int * arr, int len, int & max);

int main()
{
    int len = 0;
    int * arr = array::read<int>(len);

    int max = 0;
    bool r = find_max(arr, len, max);
    if (r) {
        std::cout << "max: " << max << std::endl;
    } else {
        std::cout << "no max found" << std::endl;
    }

    array::free(arr);

    return 0;
}
