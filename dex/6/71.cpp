// @mission: 参见71.png
#include "71.def.h"

int main()
{
    node_t * root = bitree::read<char>(bitree::CHILD_SIBLING_FORMAT);
    print_level(root);
    bitree::free(root);
    return 0;
}
