// @mission: 求解字符串s和t的全部最长公共子串

void show_all_LCS(const char * s, const char * t);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * s = xstring::read_line();
    char * t = xstring::read_line();

    show_all_LCS(s, t);

    xstring::free(s);
    xstring::free(t);

    return 0;
}
