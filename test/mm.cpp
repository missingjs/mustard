#include "common/array.h"
#include "common/utils.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    utils::print_list(arr, arr + n);
    delete[] arr;
    return 0;
}
