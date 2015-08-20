// @mission: 求二叉树宽度

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

int get_width(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();
    int width = get_width(root);
    std::cout << "width: " << width << '\n';
    delete root;
    return 0;
}
