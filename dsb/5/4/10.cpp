// @mission: 求解一个字符串的最长重复子串

#include "common/xstring.h"
using namespace mustard;

char * longest_repeat_str(const char * str);

int main()
{
    char * str = xstring::read_line();

    char * rs = longest_repeat_str(str);

    if (rs) {
        std::cout << rs << '\n';
    } else {
        std::cout << "not found\n";
    }

    xstring::free(str);
    xstring::free(rs);

    return 0;
}
