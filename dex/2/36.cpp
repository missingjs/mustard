// @brief: 采用34题所述结构，实现删除第i个结点算法

#include "common/xlist.h"
using namespace mustard;

bool remove_nth(xlist::linked_list<int> * head, int i);

int main()
{
    xlist::linked_list<int> * head = xlist::read<int>();

    int i = 0;
    std::cin >> i;

    bool result = remove_nth(head, i);
    std::cout << (result ? "succeed" : "failed") << std::endl;

    xlist::print(head);
    xlist::free(head);

    return 0;
}
