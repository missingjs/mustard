// @brief: 用顺序表表示集合，实现集合求交集运算

// a,b乱序
// @return: 新数组
int * intersect_new(const int * a, int len_a, const int * b, int len_b, int & len_c);

// a,b乱序，利用a的空间存储结果
void intersect(int * a, int len_a, const int * b, int len_b, int & len_c);

// a,b升序，结果存于新数组
int * seq_intersect_new(const int * a, int len_a, const int * b, int len_b, int & len_c);

// a,b升序，利用a的空间存储结果
void seq_intersect(int * a, int len_a, const int * b, int len_b, int & len_c);

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

    int len_c = 0;
    int * c = intersect_new(a, len_a, b, len_b, len_c);
    array::print(c, len_c);
    array::free(c);

    int * old_a = array::clone(a, len_a);

    int len_d = 0;
    intersect(a, len_a, b, len_b, len_d);
    array::print(a, len_d);
    array::free(a);

    a = old_a;

    std::sort(a, a + len_a);
    std::sort(b, b + len_b);

    int len_e = 0;
    int * e = seq_intersect_new(a, len_a, b, len_b, len_e);
    array::print(e, len_e);
    array::free(e);

    int len_f = 0;
    seq_intersect(a, len_a, b, len_b, len_f);
    array::print(a, len_f);

    array::free(a);
    array::free(b);

    return 0;
}

