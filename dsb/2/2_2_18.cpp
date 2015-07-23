// @brief: 用顺序列表示集合，设计一个算法实现集合的求差集运算

// [1] a,b元素无序
int * diff(const int * a, int len_a, const int * b, int len_b, int & len_c);

// [2] a,b元素升序
int * seq_diff(const int * a, int len_a, const int * b, int len_b, int & len_c);

#include <iostream>
#include <algorithm>
#include "common/array.h"
using namespace mustard;

int main()
{
    int len_a = 0;
    int * a = array::n_read<int>(len_a);

    int len_b = 0;
    int * b = array::n_read<int>(len_b);

    int len_c = 0;
    int * c = diff(a, len_a, b, len_b, len_c);
    array::print(c, len_c);
    array::free(c);

    if (a && len_a && b && len_b) {
        std::sort(a, a + len_a);
        std::sort(b, b + len_b);
        int len_d = 0;
        int * d = seq_diff(a, len_a, b, len_b, len_d);
        array::print(d, len_d);
        array::free(d);
    }

    return 0;
}
