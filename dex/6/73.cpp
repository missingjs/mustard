// @mission: 参见73.png
#include "73.def.h"
#include "common/xstring.h"

int main()
{
    char * content = xstring::read_line();
    node_t * root = build_tree(content);
    bitree::print(root, bitree::CHILD_SIBLING_FORMAT);
    bitree::free(root);
    delete[] content;
    return 0;
}
