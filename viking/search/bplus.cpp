// @mission: 给一组数字，建立B+树，并打印
#include "bplus.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    bp_tree * tree = create_b_plus(arr, n);
    bp_print(tree);
    bp_free(tree);

    delete[] arr;
    return 0;
}

