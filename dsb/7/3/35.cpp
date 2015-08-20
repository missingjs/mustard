// @mission: 创建一棵二叉树的镜像

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

node_t * mirror_clone(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();
    node_t * mirror = mirror_clone(root);
    bitree::print(mirror);
    delete root;
    delete mirror;
    return 0;
}
