#include <stack>

bool str_check(const char * str)
{
    if (!str || !*str) {
        return true;
    }

    const char * p = str;
    std::stack<char> stk;
    while (*p && *p != '&') {
        stk.push(*p++);
    }

    if (!*p) {
        return false;
    }

    ++p;

    while (*p && !stk.empty()) {
        if (*p == stk.top()) {
            stk.pop();
            ++p;
        } else {
            return false;
        }
    }

    return (!*p && stk.empty());
}
