// @brief: A,B,C是三个递增有序的线性表，对A作如下操作：删去既在B中又在C中出现的元素。以顺序表作为存储，且不得申请额外空间存储中间结果

#include "common/array.h"
using namespace mustard;

void process(int * a, int & La, const int * b, int Lb, const int * c, int Lc);

int main()
{
    int La = 0;
    int * a = array::read<int>(La);

    int Lb = 0;
    int * b = array::read<int>(Lb);

    int Lc = 0;
    int * c = array::read<int>(Lc);

    process(a, La, b, Lb, c, Lc);
    array::print(a, La);

    array::free(a);
    array::free(b);
    array::free(c);

    return 0;
}
