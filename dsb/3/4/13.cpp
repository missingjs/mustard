// @brief: 将3-4-9改写为非递归算法
#include "common/array.h"
using namespace mustard;

void print_permutation(char * str, int len);

int main()
{
    int len = 0;
    char * str = array::read<char>(len);

    print_permutation(str, len);

    array::free(str);

    return 0;
}

