// @mission: 给两组数字，利用第一组建立二叉排序树，再从树中删除第二组中包含的数字
#include "bstree.def.h"
#include "common/array.h"

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);
    int m = 0;
    int * del = array::read<int>(m);

    node_t * root = create_bst(arr, n);
    bitree::print(root, bitree::HIERARCHY_FORMAT);

    root = remove(root, del, m);
    bitree::print(root, bitree::HIERARCHY_FORMAT);

    delete[] arr;
    delete[] del;
    bitree::free(root);

    return 0;
}
