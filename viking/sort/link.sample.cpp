#include "link.def.h"
#include <cstddef>
#include <iostream>

void _insert(slink * s, int k)
{
    int p = s->vect[0].next, q = 0;
    while (p > 0 && s->vect[p].key < k) {
        q = p;
        p = s->vect[p].next;
    }
    
    int i = s->key_count + 1;
    s->vect[i].key = k;
    s->vect[q].next = i;
    s->vect[i].next = p;
    ++s->key_count;
}

slink * build_links(int * arr, int n)
{
    if (!arr || n <= 0) {
        return NULL;
    }
    slink * s = new slink;
    s->vect = new snode[n+1];
    s->key_count = 0;

    for (int i = 0; i < n; ++i) {
        _insert(s, arr[i]);
    }

    return s;
}

int _find_next(slink * s, int i, int p)
{
    while(p > 0 && p <= i) {
        p = s->vect[p].next;
    }
    return p;
}

void _print(slink * s)
{
    std::cout << s->vect[0].next << " -> ";
    for (int i = 1; i <= s->key_count; ++i) {
        std::cout << s->vect[i].key << ',' << s->vect[i].next << ' ';
    }
    std::cout << '\n';
}

void dump(int * arr, slink * s)
{
    int i = 1, p = s->vect[0].next, t = 0;
    snode tmp;

    while (p != 0) {
        if (i != p) {
            t = p;
            p = s->vect[p].next;
            tmp = s->vect[t];
            s->vect[t] = s->vect[i];
            s->vect[i] = tmp;
            s->vect[i].next = t;
        }
        p = _find_next(s, i, p);
        ++i;
    }

    for (int i = 1; i <= s->key_count; ++i) {
        arr[i-1] = s->vect[i].key;
    }
}

void free_slink(slink * s)
{
    delete[] s->vect;
    delete s;
}
