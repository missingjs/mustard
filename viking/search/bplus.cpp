// @mission: 给两组数字，根据第一组建立B+树，再从树中删除第二组中数字
#include "bplus.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    bp_tree * tree = create_b_plus(arr, n);
    bp_print(tree);

    int m = 0;
    int * del = array::read<int>(m);

    remove_from_b_plus(tree, del, m);
    bp_print(tree);

    bp_free(tree);

    delete[] arr;
    delete[] del;
    return 0;
}

