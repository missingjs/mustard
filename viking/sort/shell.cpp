// @mission: 实现希尔排序
#include "shell.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    int delt[] = {5,3,1};

    shell_sort(arr, n, delt, sizeof(delt) / sizeof(int));

    array::print(arr, n);

    delete[] arr;
    return 0;
}
