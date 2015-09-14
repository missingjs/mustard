// @mission: 实现表插入排序
#include "link.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    slink * s = build_links(arr, n);

    dump(arr, s);

    array::print(arr, n);

    free_slink(s);
    delete[] arr;
    return 0;
}
