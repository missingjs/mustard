#include <stack>

bool is_match(const char * str)
{
    if (!str || !*str) {
        return true;
    }

    std::stack<char> stk;
    const char * p = str;
    for (; *p; ++p) {
        if (*p == '{' || *p == '[' || *p == '(') {
            stk.push(*p);
        } else if (*p == '}') {
            if (!stk.empty() && stk.top() == '{') {
                stk.pop();
            } else {
                break;
            }
        } else if (*p == ']') {
            if (!stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                break;
            }
        } else if (*p == ')') {
            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            } else {
                break;
            }
        }
    }

    return stk.empty() && !*p;
}
