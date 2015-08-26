// @mission: 参见70.png
#include "70.def.h"
#include "common/xstring.h"

int main()
{
    char * content = xstring::read_line();
    node_t * root = build_hierarchical(content);
    bitree::print(root);
    bitree::free(root);
    delete[] content;
    return 0;
}
