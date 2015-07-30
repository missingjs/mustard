// @brief: 参见27.png

#include "common/array.h"
using namespace mustard;

void intersection(int * a, int La, const int * b, int Lb, int &Lc);

int main()
{
    int La = 0;
    int * a = array::read<int>(La);

    int Lb = 0;
    int * b = array::read<int>(Lb);

    intersection(a, La, b, Lb, La);
    array::print(a, La);

    array::free(a);
    array::free(b);

    return 0;
}
