#include "common/slist.h"
using namespace mustard;

typedef slist::node<char> node_t;

struct kp
{
    char data;
    kp * next;
    kp * jump;

    kp(char d = 0)
        : data(d), next(NULL), jump(NULL)
    {}
};

int get_length(node_t * head)
{
    int i = 0;
    node_t * p = head->next;
    while (p) {
        p = p->next;
        ++i;
    }
    return i;
}

kp * from_pattern(node_t * pat)
{
    kp head, *last = &head;
    node_t * p = pat;
    while (p) {
        kp * n = new kp(p->data);
        last->next = n;
        last = n;
        p = p->next;
    }
    return head.next;
}

kp * make_pattern(node_t * pat)
{
    kp * head = from_pattern(pat);
    head->next->jump = head;

    kp * p = head->next;
    kp * q = head;

    while (p) {
        if (q == head || p->data == q->data) {
            p = p->next;
            q = q->next;
            if (p && p->data == q->data) {
                p->jump = q->jump;
            } else if (p) {
                p->jump = q;
            } else {
                head->jump = q;
            }
        } else {
            q = q->jump;
        }
    }

    return head;
}

void kp_free(kp * k)
{
    while (k) {
        kp * t = k;
        k = k->next;
        delete t;
    }
}

void linked_kmp(node_t * str, node_t * pat)
{
    if (!str || !pat || !str->next || !pat->next) {
        return;
    }

    int pat_len = get_length(pat);

    kp * pattern = make_pattern(pat);

    node_t * p = str->next;
    kp * q = pattern->next;

    int i = 0;
    while (p) {
        while (p && q) {
            if (q == pattern || p->data == q->data) {
                p = p->next;
                ++i;
                q = q->next;
            } else {
                q = q->jump;
            }
        }
        if (!q) {
            std::cout << (i - pat_len) << ' ';
        }
        q = pattern->jump;
    }

    kp_free(pattern);

    std::cout << '\n';
}
