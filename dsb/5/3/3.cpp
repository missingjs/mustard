// @mission: 在链串s中，将第i(1<=i<=n)个字符开始的j个字符构成的子串用串t替换，返回产生的新串

#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

node_t * replace(node_t * s, int i, int j, node_t * t);

int main()
{
    node_t * s = slist::read<char>();
    int i = 0, j = 0;
    std::cin >> i >> j;
    node_t * t = slist::read<char>();

    node_t * new_str = replace(s, i, j, t);

    slist::print(new_str);

    slist::free(s);
    slist::free(t);
    slist::free(new_str);

    return 0;
}
