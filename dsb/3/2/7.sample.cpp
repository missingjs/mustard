#include "common/array.h"
using namespace mustard;

struct pt_holder {
    
    char * ptr;

    pt_holder(char * p = NULL) :
        ptr(p)
    {}

    ~pt_holder()
    {
        delete[] ptr;
    }
};

bool test_matching(const char * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return true;
    }

    char * stack = new char[len];
    pt_holder hd(stack);
    int top = 0;

    for (int i = 0; i < len; ++i) {
        char ch = arr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[top++] = ch;
        } else if (ch == ')') {
            if (top > 0 && stack[top-1] == '(') {
                --top;
            } else {
                return false;
            }
        } else if (ch == ']') {
            if (top > 0 && stack[top-1] == '[') {
                --top;
            } else {
                return false;
            }
        } else if (ch == '}') {
            if (top > 0 && stack[top-1] == '{') {
                --top;
            } else {
                return false;
            }
        }
    }

    return top == 0;
}
