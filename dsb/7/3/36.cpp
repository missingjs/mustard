// @mission: 给定一棵二叉树b，两个元素r和s，求b中同时包含r和s的最小子树，即求r和s的最近公共祖先。分别考虑带有和不带有指向父结点指针的情况

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

struct nps
{
    char ch;
    bitree::node<nps> * parent;
    nps()
        : ch(0), parent(NULL)
    {}
};

std::ostream & operator<<(std::ostream & out, const nps & _n)
{
    return (out << _n.ch);
}

typedef bitree::node<nps> n2_t;

node_t * minimal_common_ancestor(node_t * root, char a, char b);
n2_t * convert(node_t * root);
n2_t * minimal_common_ancestor(n2_t * root, char a, char b);

int main()
{
    node_t * root = bitree::read<char>();
    char a, b;
    std::cin >> a >> b;
    node_t * t = minimal_common_ancestor(root, a, b);
    bitree::print(t);

    n2_t * n2_root = convert(root);
    n2_t * n2_mca = minimal_common_ancestor(n2_root, a, b);
    bitree::print(n2_mca);
    delete n2_mca;

    delete root;

    return 0;
}
