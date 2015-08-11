// @mission: 设计Strcmp(s,t)算法

int str_cmp(const char * s1, const char * s2);

#include <iostream>
#include "common/xstring.h"
using namespace mustard;

int main()
{
    int s1_len = 0;
    char * s1 = xstring::read(s1_len);

    int s2_len = 0;
    char * s2 = xstring::read(s2_len);

    int c = str_cmp(s1, s2);
    std::cout << c << std::endl;

    xstring::free(s1);
    xstring::free(s2);

    return 0;
}
