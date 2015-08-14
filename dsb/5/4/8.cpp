// @mission: 在串str中查找子串substr最后一次出现的位置

int find_last_index(const char * str, const char * substr);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * str = xstring::read_line();
    char * substr = xstring::read_line();

    int index = find_last_index(str, substr);

    std::cout << "last index: " << index << '\n';

    xstring::free(str);
    xstring::free(substr);

    return 0;
}
