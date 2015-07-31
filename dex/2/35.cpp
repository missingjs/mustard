// @brief: 利用在34题所述存储结构，在第i个结点之前插入一个结点

#include "common/xlist.h"
using namespace mustard;

bool insert(xlist::linked_list<int> * head, int i, int x);

int main()
{
    xlist::linked_list<int> * head = xlist::read<int>();

    int i = 0, x = 0;
    std::cin >> i >> x;

    bool result = insert(head, i, x);

    std::cout << std::boolalpha << "result: " << result << std::endl;

    xlist::print(head);

    xlist::free(head);

    return 0;
}
