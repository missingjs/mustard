// @mission: 由算术表达式的前缀式求后缀式，前缀表达式无语法错误

void pre_to_post(const char * pre, char * post);

#include <cstring>
#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * pre = xstring::read_line();
    char * post = new char[strlen(pre) + 1];

    pre_to_post(pre, post);

    xstring::print(post);

    xstring::free(pre);
    delete[] post;

    return 0;
}
