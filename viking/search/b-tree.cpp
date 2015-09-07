// @mission: 给一组整数，建立B-树
#include "common/array.h"
#include "b-tree.def.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    b_node * root = create_b_tree(arr, n);

    b_print (root);
    std::cout << '\n';

    b_free(root);
    delete[] arr;

    return 0;
}
