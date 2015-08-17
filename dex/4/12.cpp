// @mission: 实现串的替换操作Replace(&s,t,v)

char * replace(const char * str, const char * pat, const char * rep);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * str = xstring::read_line();
    char * pat = xstring::read_line();
    char * rep = xstring::read_line();

    char * new_str = replace(str, pat, rep);

    xstring::print(new_str);

    xstring::free(str);
    xstring::free(pat);
    xstring::free(rep);
    xstring::free(new_str);

    return 0;
}
