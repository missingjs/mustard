// @brief: 用顺序表表示集合，设计一个算法实现集合的求并集运算

// len_c -> 结果数组长度
// @return: 结果数组

// [1] a,b为无序数组
int * get_union(const int * a, int len_a, const int * b, int len_b, int & len_c);

// [2] a,b为有序数组
int * get_union_seq(const int * a, int len_a, const int * b, int len_b, int & len_c);

#include <iostream>
#include <algorithm>
#include "common/array.h"
using namespace mustard;

int main()
{
    int *a = NULL, len_a = 0;
    a = array_n_read<int>(len_a);

    int *b = NULL, len_b = 0;
    b = array_n_read<int>(len_b);

    int *c = NULL, len_c = 0;
    c = get_union(a, len_a, b, len_b, len_c);
    array_print(c, len_c);
    array_free(c);

    if (a && len_a && b && len_b) {
        std::sort(a, a + len_a);
        std::sort(b, b + len_b);
        int *d = NULL, len_d = 0;
        d = get_union_seq(a, len_a, b, len_b, len_d);
        array_print(d, len_d);
        array_free(d);
    }

    return 0;
}
