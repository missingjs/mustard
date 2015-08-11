// @mission: 设计递归算法，利用串基本运算StrLength(), SubString()和Concat()将字符串逆置

void reverse_local(char * str);

char * reverse(const char * str);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    int len = 0;
    char * str = xstring::read(len);

    char * rstr = reverse(str);
    xstring::print(rstr);

    reverse_local(str);
    xstring::print(str);

    xstring::free(str);
    xstring::free(rstr);

    return 0;
}
