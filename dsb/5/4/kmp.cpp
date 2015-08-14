// @mission: 实现KMP算法

#include "common/xstring.h"
using namespace mustard;

int find_sub(const char * str, const char * sub);
void print_all_index(const char * str, const char * sub);

int main()
{
    char * str = xstring::read();
    char * sub = xstring::read();

    int index = find_sub(str, sub);

    std::cout << "index: " << index << '\n';

    print_all_index(str, sub);

    xstring::free(str);
    xstring::free(sub);

    return 0;
}
