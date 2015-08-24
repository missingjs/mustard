// @mission: 参见39.png

#include "39.def.h"

std::ostream & operator<<(std::ostream & out, const pnode & n)
{
    return (out << n.ch);
}

std::istream & operator>>(std::istream & in, pnode & n)
{
    return (in >> n.ch);
}

bool operator!=(const pnode & p1, const pnode & p2)
{
    return p1.ch != p2.ch;
}

namespace mustard {
namespace bitree {
template <>
node_t * read_hierarchy<pnode>()
{
    return _read_hierarchy_char<node_t>();
}
}}

int main()
{
    node_t * root = bitree::read<pnode>();

    init(root);

    post_order_traverse(root);

    bitree::free(root);

    return 0;
}
