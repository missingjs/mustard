// @mission: 参见67.png
#include "67.def.h"

int main()
{
    node_t * root = create_by_dual();
    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);
    bitree::free(root);
    return 0;
}
