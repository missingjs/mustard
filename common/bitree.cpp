#include "bitree.h"

#include <string>
#include <stack>
#include <cctype>

namespace mustard {

namespace bitree {

char _next_char(const char * & p)
{
    while (*p && isspace(*p)) {
        ++p;
    }
    return *p ? *p++ : *p;
}

template <>
node<char> * read_hierarchy<char>()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::stack<node<char>*> stk;
    const char * p = input_line.c_str();
    node<char> * nd = NULL;
    while (*p) {
        char ch = _next_char(p);
        if (!ch) {
            break;
        }
        switch (ch) {
            case '(':
                stk.push(nd);
                nd = NULL;
                break;
            case ')':
                stk.top()->rc = nd;
                nd = stk.top();
                stk.pop();
                break;
            case ',':
                stk.top()->lc = nd;
                nd = NULL;
                break;
            default:
                nd = new node<char>(ch);
        }
    }
    return nd;
}

template <>
threading_node<char> * read_hierarchy()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::stack<threading_node<char>*> stk;
    const char * p = input_line.c_str();
    threading_node<char> * nd = NULL;
    while (*p) {
        char ch = _next_char(p);
        if (!ch) {
            break;
        }   
        switch (ch) {
            case '(':
                stk.push(nd);
                nd = NULL;
                break;
            case ')':
                stk.top()->rc = nd; 
                nd = stk.top();
                stk.pop();
                break;
            case ',':
                stk.top()->lc = nd; 
                nd = NULL;
                break;
            default:
                nd = new threading_node<char>(
                        _threading<char>(ch));
        }
    }
    return nd;
}

} // namespace ::mustard::bitree

} // namespace ::mustard
