// @mission: 实现递归算法，根据形如A(B(E,F),C(G),D)的字符序列构造树的孩子链表，再实现其逆过程
#include "75.def.h"
#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * content = xstring::read_line();
    tree_t * tree = build_tree(content);
    print_tree(tree);
    free_tree(tree);
    delete[] content;
    return 0;
}
