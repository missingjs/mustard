#include <iostream>

#include "common/array.h"
#include "poly.h"
using namespace mustard;

exp_link_node * read_exp_list()
{
    int len_c = 0;
    int * coef = array::read<int>(len_c);

    int len_e = 0;
    int * exp = array::read<int>(len_e);

    if (len_c != len_e) {
        std::cout << "error format\n";
        exit(1);
    }

    exp_link_node head, *last = &head;
    for (int i = 0; i < len_c; ++i) {
        exp_link_node * n = new exp_link_node(coef[i], exp[i]);
        last->next = n;
    }

    delete[] coef;
    delete[] exp;

    return head.next;
}

void free_exp_list(exp_link_node * h)
{
    exp_link_node * p = h;
    while (p) {
        h = p->next;
        delete p;
        p = h;
    }
}

void print_exp_list(exp_link_node * h)
{
    exp_link_node * p = NULL;
    while (h) {
        std::cout << '(' << h->c << ',' << h->e << ')' << ' ';
        h = h->next;
    }
    std::cout << '\n';
}
