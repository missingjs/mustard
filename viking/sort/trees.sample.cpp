#include "trees.def.h"
#include <limits>
#include <iostream>

int get_k(int n)
{
    int i = 1;
    while (i < n) {
        i = i << 1;
    }
    return i;
}

void _adjust(_ts * t)
{
    int j = t[1].i;
    t[j].v = std::numeric_limits<int>::max();
    while (j > 1) {
        if (j % 2) {
            --j;
        }
        if (t[j].v < t[j+1].v) {
            t[j/2] = t[j];
        }
        else {
            t[j/2] = t[j+1];
        }
        j /= 2;
    }
}

void _dump(_ts * t, int n)
{
    for (int i = 1; i < n; ++i) {
        std::cout << '(' << t[i].v << ',' << t[i].i << ')' << ' ';
    }
    std::cout << '\n';
}

_ts * build_complete_tree(int * arr, int n, int & len)
{
    int k = get_k(n);

    len = k * 2;
    _ts * ts = new _ts[len];
    int i = 0;
    for (; i < n; ++i) {
        ts[k+i].v = arr[i];
        ts[k+i].i = k + i;
    }
    for (; i < k; ++i) {
        ts[k+i].v = std::numeric_limits<int>::max();
        ts[k+i].i = k + i;
    }

    for (i = len - 1; i > 1; i -= 2) {
        if (ts[i].v < ts[i-1].v) {
            ts[i/2] = ts[i];
        } 
        else {
            ts[i/2] = ts[i-1];
        }
    }

    return ts;
}

void tree_select_output(_ts * ts, int len, int * arr, int n)
{
    int j = 0;
    arr[j++] = ts[1].v;

    while (j < n) {
        _adjust(ts);
        arr[j++] = ts[1].v;
    }
}

