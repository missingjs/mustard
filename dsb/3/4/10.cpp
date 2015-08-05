// @brief: 求解组合问题

#include "common/array.h"
using namespace mustard;

void print_combination(const char * str, int n, int m);

int main()
{
    int len = 0;
    char * str = array::read<char>(len);

    int n = len, m = 0;
    std::cin >> m;

    print_combination(str, n, m);

    array::free(str);

    return 0;
}
