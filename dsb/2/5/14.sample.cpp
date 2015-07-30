#include <stddef.h>
#include "common/dlist.h"
using namespace mustard;

typedef dlist::node<int> node_t;

dlist::node<int> * remove_first(dlist::node<int> * tail, int x)
{
    if (tail == NULL) {
        return NULL;
    }

    dlist::node<int> * head = tail->next;

    if (head == tail) {
        if (head->data == x) {
            delete head;
            return NULL;
        } else {
            return head;
        }
    }
    
    // add fake head
    node_t fake_head;
    fake_head.next = head;
    head->prev = &fake_head;
    fake_head.prev = tail;
    tail->next = &fake_head;

    node_t * p = head;
    for (; p != &fake_head && p->data != x; p = p->next)
        ;;
    if (p != &fake_head) {
        node_t * p0 = p->prev;
        node_t * p2 = p->next;
        p0->next = p2;
        p2->prev = p0;
        delete p;
    }

    head = fake_head.next;
    tail = fake_head.prev;
    tail->next = head;
    head->prev = tail;
    return tail;
}
