// @mission: 给定一个由若干字符构成的集合，打印其幂集

void print_powerset(const char * seq);

#include "common/xstring.h"
using namespace mustard;

int main()
{
    char * str = xstring::read();
    print_powerset(str);
    delete[] str;
    return 0;
}
