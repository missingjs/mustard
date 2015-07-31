// @brief: 参见34.png

#include "common/xlist.h"
using namespace mustard;

void print_forward(xlist::linked_list<int> * head);

void print_backward(xlist::linked_list<int> * head);

int main()
{
    xlist::linked_list<int> * head = xlist::read<int>();

    print_forward(head);

    print_backward(head);

    xlist::free(head);

    return 0;
}
