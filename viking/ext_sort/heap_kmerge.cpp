// @mission: 利用堆排序实现K路平衡归并
#include "heap_kmerge.def.h"
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
    kmerge_by_heap(group, k, output);

    array::print(output, n);

    delete[] arr;
    delete[] group;
    delete[] output;
    return 0;
}
