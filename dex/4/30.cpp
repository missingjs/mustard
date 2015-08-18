// @mission: 打印字符串s所有最长重复子串和位置

void print_all_LRS(const char * str);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * str = xstring::read_line();

    print_all_LRS(str);

    xstring::free(str);

    return 0;
}
