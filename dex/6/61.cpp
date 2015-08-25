// @mission: 求一棵以孩子-兄弟链表表示的树的度
#include "61.def.h"

int main()
{
    node_t * root = bitree::read<char>(bitree::CHILD_SIBLING_FORMAT);
    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);
    int d = get_degree(root);
    std::cout << d << '\n';
    bitree::free(root);
    return 0;
}
