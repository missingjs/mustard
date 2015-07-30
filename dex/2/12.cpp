// @brief: 参见12.png

#include "common/array.h"
using namespace mustard;

int compare(const int * a, int len_a, const int * b, int len_b);

int main()
{
    int len_a = 0;
    int * a = array::read<int>(len_a);

    int len_b = 0;
    int * b = array::read<int>(len_b);

    int c = compare(a, len_a, b, len_b);

    std::cout << "result: " << c << std::endl;

    array::free(a);
    array::free(b);

    return 0;
}
