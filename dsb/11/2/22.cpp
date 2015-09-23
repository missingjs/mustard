// @mission: 判断一个序列是否是大根堆
#include "22.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    bool k = is_big_heap(arr, n);

    std::cout << std::boolalpha << k << '\n';

    delete[] arr;
    return 0;
}
