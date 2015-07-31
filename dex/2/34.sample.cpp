#include <iostream>
#include "common/xlist.h"
using namespace mustard;

typedef xlist::node<int> node_t;

void print_forward(xlist::linked_list<int> * head)
{
    if (head == NULL || head->left == NULL) {
        std::cout << "empty list\n";
        return;
    }

    node_t *p = head->left, *last = NULL, *t = NULL;
    while (p) {
        std::cout << p->data << ' ';
        t = p;
        p = _xor(p->ptr, last);
        last = t;
    }
    std::cout << '\n';
}

void print_backward(xlist::linked_list<int> * head)
{
    if (head == NULL || head->right == NULL) {
        std::cout << "empty list\n";
        return;
    }

    node_t *p = head->right, *last = NULL, *t = NULL;
    while (p) {
        std::cout << p->data << ' ';
        t = p;
        p = _xor(p->ptr, last);
        last = t;
    }
    std::cout << '\n';
}
