// @brief: 给定一个字符序列，利用栈的基本操作push和pop，打印所有可能的输出序列

#include "common/array.h"
using namespace mustard;

void seq_exhaust(const int * arr, int len);

int main()
{
    int len = 0;
    int * arr = array::read<int>(len);

    seq_exhaust(arr, len);

    array::free(arr);

    return 0;
}
