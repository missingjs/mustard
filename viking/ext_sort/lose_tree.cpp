// @mission: 输入一组整数，将之分为K段并分别排序，利用败者树进行K路平衡归并，得到一组有序整数
#include "lose_tree.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0, size_of_seg = 0;
    int * arr = array::read<int>(n);

    std::cin >> size_of_seg;

    int k = 0;
    Array * group = split(arr, n, size_of_seg, k);

    for (int i = 0; i < k; ++i) {
        insert_sort(group[i].arr, group[i].len);
    }

    int * output = new int[n];
    k_merge(group, k, output);

    array::print(output, n);

    delete[] arr;
    delete[] group;
    delete[] output;
    return 0;
}
