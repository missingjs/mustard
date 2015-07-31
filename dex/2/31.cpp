// @brief: 一个单链表中含有三类字符（字母、数字、其它字符），将该链表按字符类型分割为三个循环链表

#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

void split(node_t * h, node_t * & alpha, node_t * & digit, node_t * &punct);

int main()
{
    node_t * h = slist::read<char>();

    node_t *alpha = NULL, *digit = NULL, *punct = NULL;

    split(h, alpha, digit, punct);

    alpha = slist::de_circular(alpha);
    digit = slist::de_circular(digit);
    punct = slist::de_circular(punct);

    slist::print(alpha);
    slist::print(digit);
    slist::print(punct);

    slist::free(alpha);
    slist::free(digit);
    slist::free(punct);

    return 0;
}
