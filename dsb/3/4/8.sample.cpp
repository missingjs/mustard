#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

int count_nodes(node_t * h)
{
    if (!h) {
        return 0;
    }

    return 1 + count_nodes(h->next);
}

void p_f(node_t * h)
{
    if (h) {
        std::cout << h->data << ' ';
        p_f(h->next);
    }
}

void print_forward(node_t * h)
{
    p_f(h);
    std::cout << '\n';
}

void p_b(node_t * h)
{
    if (h) {
        p_b(h->next);
        std::cout << h->data << ' ';
    }
}

void print_backward(node_t * h)
{
    p_b(h);
    std::cout << '\n';
}

void r_f(node_t * & ph, int x)
{
    if (ph) {
        if (ph->data == x) {
            node_t * t = ph;
            ph = t->next;
            delete t;
            return;
        }
        r_f(ph->next, x);
    }
}

node_t * remove_first_x(node_t * h, int x)
{
    r_f(h, x);
    return h;
}

void r_a(node_t * & ph, int x)
{
    if (ph) {
        if (ph->data == x) {
            node_t * t = ph;
            ph = ph->next;
            delete t;
            r_a(ph, x);
        } else {
            r_a(ph->next, x);
        }
    }
}

node_t * remove_all_x(node_t * h, int x)
{
    r_a(h, x);
    return h;
}

int g_m(node_t * h)
{
    if (!h->next) {
        return h->data;
    }

    int n = h->data;
    int k = g_m(h->next);
    return n > k ? n : k;
}

bool get_max(node_t * h, int & max)
{
    if (!h) {
        return false;
    }

    max = g_m(h);
    return true;
}

int g_min(node_t * h)
{
    if (!h->next) {
        return h->data;
    }

    int n = h->data;
    int k = g_min(h->next);
    return n < k ? n : k;
}

bool get_min(node_t * h, int & min)
{
    if (!h) {
        return false;
    }

    min = g_min(h);
    return true;
}

