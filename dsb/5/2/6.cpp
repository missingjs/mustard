// @mission: 设计算法RepStr(s,i,j,t)，在串s中将第i(1<=i<=n)个字符开始的j个字符构成的了串用串t替换，并返回产生的新串

char * replace(const char * s, int i, int j, const char * t);

#include <iostream>
#include <cstring>
#include "common/xstring.h"
using namespace mustard;

int main()
{
    int ss = 0;
    char * s = xstring::read(ss);

    int i = 0, j = 0;
    std::cin >> i >> j;

    int ts = 0;
    char * t = xstring::read(ts);

    char * nstr = replace(s, i, j, t);

    xstring::print(nstr);

    xstring::free(s);
    xstring::free(t);
    xstring::free(nstr);

    return 0;
}
