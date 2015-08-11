// @mission: 设计一个递归算法，利用串的基本去处SubStr()判断字符x是否在串s中，并实现对应的非递归算法

bool exists(const char * str, char x);
bool exists2(const char * str, char x);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    int len = 0;
    char * str = xstring::read(len);

    char x = 0;
    std::cin >> x;

    bool r = exists(str, x);
    bool r2 = exists2(str, x);

    std::cout << std::boolalpha << r << ',' << r2 << '\n';

    xstring::free(str);

    return 0;
}
