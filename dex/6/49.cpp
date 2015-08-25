// @mission: 判别给定二叉树是否为完全二叉树

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

bool is_complete(node_t * t);

int main()
{
    node_t * root = bitree::read<char>();
    bool f = is_complete(root);
    std::cout << std::boolalpha << f << '\n';
    bitree::free(root);
    return 0;
}
