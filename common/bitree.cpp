#include "bitree.h"

#include <string>
#include <stack>
#include <cctype>

namespace mustard {

namespace bitree {

std::istream & operator>>(std::istream & in, ch_data & c)
{
    return (in >> c.ch);
}

std::ostream & operator<<(std::ostream & out, const ch_data & c)
{
    return (out << c.ch);
}

bool operator!=(const ch_data & c1, const ch_data & c2)
{
    return c1.ch != c2.ch;
}

char _next_char(const char * & p)
{
    while (*p && isspace(*p)) {
        ++p;
    }
    return *p ? *p++ : *p;
}

template <>
node<char> * read_hierarchy< char, node<char> >()
{
    typedef node<char> node_t;
    return _read_hierarchy_char<node_t>();
}

template <>
threading_node<char> * read_hierarchy< char, threading_node<char> >()
{
    typedef threading_node<char> node_t;
    return _read_hierarchy_char<node_t>();
}

} // namespace ::mustard::bitree

} // namespace ::mustard
