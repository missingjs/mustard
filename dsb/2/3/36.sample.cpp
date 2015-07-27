#include <stddef.h>
#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

bool is_sub_list(node_t * a, node_t * b)
{
    if (b == NULL) {
        return true;
    } else if (a == NULL) {
        return false;
    }

    while (a) {
        node_t * pa = a;
        node_t * pb = b;
        while (pa && pb && pa->data == pb->data) {
            pa = pa->next;
            pb = pb->next;
        }

        if (!pb) {
            return true;
        }

        a = a->next;
    }

    return false;
}
