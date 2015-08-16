// @mission: 求解两字符串的最长公共子串

char * longest_common_substring(const char * s1, const char * s2);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * s1 = xstring::read_line();
    char * s2 = xstring::read_line();

    char * cs = longest_common_substring(s1, s2);

    xstring::print(cs);

    xstring::free(cs);
    xstring::free(s1);
    xstring::free(s2);

    return 0;
}
