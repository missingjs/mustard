// @mission: 二叉树繁茂度定义为各层结点数的最大值与树的高度的乘积，求二叉树繁茂度
#include "52.def.h"

int main()
{
    node_t * root = bitree::read<Lnode>();
    int f = get_flourish(root);
    std::cout << f << '\n';
    bitree::free(root);
    return 0;
}
