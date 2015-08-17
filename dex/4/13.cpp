// @mission: 从串s中删除所有和t相同的子串

char * remove_sub(const char * s, const char * t);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * s = xstring::read_line();
    char * t = xstring::read_line();

    char * r = remove_sub(s,t);
    xstring::print(r);

    xstring::free(s);
    xstring::free(t);

    xstring::free(r);
    return 0;
}
