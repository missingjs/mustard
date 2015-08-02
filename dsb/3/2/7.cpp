// @brief: 表达式中允许包含3种括号：圆括号、方括号和大括号，采用顺序栈判断表达式中的括号是否正确配对

#include "common/array.h"
using namespace mustard;

bool test_matching(const char * arr, int len);

int main()
{
    int len;
    char * arr = array::read<char>(len);

    bool result = test_matching(arr, len);

    std::cout << (result ? "matching" : "not matching") << std::endl;

    array::free(arr);

    return 0;
}
