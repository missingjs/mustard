// @mission: 给一组整数，建立AVL树
#include "avl.def.h"

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    node_t * root = create_avl(arr, n);
    bitree::print(root, bitree::HIERARCHY_FORMAT);
    bitree::free(root);

    delete[] arr;
    return 0;
}
