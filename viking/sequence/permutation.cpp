// @mission: N个字母取M个排列

void print_permutation(char * arr, int n, int m);

#include "common/array.h"
using namespace mustard;

int main()
{
    int n = 0;
    char * arr = array::read<char>(n);
    int m = 0;
    std::cin >> m;

    print_permutation(arr, n, m);

    array::free(arr);

    return 0;
}
