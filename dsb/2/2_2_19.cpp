// @brief: A B为两个顺序表，元素个数分别为m和n，数据由小到大排列，且m+n个数据没有重复

// [1] 合并A和B，并且数据仍由小到大排列，存到别一个顺序表C中
int * make_union(const int * a, int len_a, const int * b, int len_b, int & len_c);

// [2] 若顺序表B空间大小为m+n，试将合并后的数据放于B中
void make_union_b(const int * a, int len_a, int * b, int len_b, int & len_c);

// [3] 若A有m+n个元素，前m个有序，后n个有序，试将整个A置为有序
void in_sort(int * a, int m, int n);

#include <iostream>
#include <cstring>
#include "common/array.h"
using namespace mustard;

int main()
{
    int len_a = 0;
    int * a = array::n_read<int>(len_a);

    int len_b = 0;
    int * b = array::n_read<int>(len_b);

    int len_c = 0;
    int * c = make_union(a, len_a, b, len_b, len_c);
    array::print(c, len_c);
    array::free(c);

    int * b2 = new int[len_a + len_b];
    int len_b2 = 0;
    memcpy(b2, b, sizeof(int) * len_b);
    make_union_b(a, len_a, b2, len_b, len_b2);
    array::print(b2, len_b2);

    int * A = b2;
    memcpy(A, a, sizeof(int) * len_a);
    memcpy(A + len_a, b, sizeof(int) * len_b);
    array::print(A, len_a + len_b);
    in_sort(A, len_a, len_b);
    array::print(A, len_a + len_b);
    array::free(A);

    return 0;
}
