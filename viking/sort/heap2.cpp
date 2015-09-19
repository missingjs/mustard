// @mission: 实现make_heap, push_heap, pop_heap操作，分别利用(make_heap,pop_heap)和(push_heap,pop_heap)两组操作对输入序列进行排序
#include "heap2.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);
    int * a2 = new int[n];
    int * h = arr - 1, *h2 = a2 - 1;

    for (int i = 0; i < n; ++i) {
        push_heap(h2, i, arr[i]);
    }

    std::cout << "make_heap/pop_heap: ";
    make_heap(h, n);
    for (int i = n; i > 0; --i) {
        std::cout << pop_heap(h, i) << ' ';
    }
    std::cout << '\n';

    std::cout << "push_heap/pop_heap: ";
    for (int i = n; i > 0; --i) {
        std::cout << pop_heap(h2, i) << ' ';
    }
    std::cout << '\n';

    delete[] arr;
    delete[] a2;
    return 0;
}
