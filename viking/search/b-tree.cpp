// @mission: 给两组整数，第一组建立B-树，并从树中删除第二组的数字
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

    int m = 0;
    int * del = array::read<int>(m);
    root = remove_element(root, del, m);
    b_print(root);
    std::cout << '\n';

    b_free(root);
    delete[] arr;
    delete[] del;

    return 0;
}
