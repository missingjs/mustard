// @mission: 输入出二叉树表示的算术表达式，根据运算符优先级自动输出括号

#include "51.def.h"

int main()
{
    node_t * root = bitree::read<char>();

    char * output = new char[1024];

    show_expr(root, output);

    std::cout << output << '\n';

    delete[] output;
    bitree::free(root);

    return 0;
}
