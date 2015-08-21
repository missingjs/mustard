// @mission: 参见40.png

#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

void rotate_print(node_t * root);

int main()
{
    node_t * root = bitree::read<char>();
    rotate_print(root);
    delete root;
    return 0;
}
