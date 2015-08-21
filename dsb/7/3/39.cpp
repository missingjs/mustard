// @mission: 一棵二叉链存储的二叉树，利用结点的右子指针将其叶子结点按从左往右的顺序串成一个单链表

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

node_t * link_leaf(node_t * root);
void print_link_leaf(node_t * h);
void delink_leaf(node_t * h);

int main()
{
    node_t * root = bitree::read<char>();

    node_t * head = link_leaf(root);

    print_link_leaf(head);

    delink_leaf(head);

    delete root;

    return 0;
}
