// @mission: 给定字符序列，只借助栈的push/pop操作，打印所有可能输出序列

void all_pushpop(const char * seq);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * seq = xstring::read();
    all_pushpop(seq);
    delete[] seq;
    return 0;
}
