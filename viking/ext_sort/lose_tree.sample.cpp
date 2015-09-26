#include "lose_tree.def.h"
#include "common/array.h"
#include <cstring>
#include <iostream>
using namespace mustard;

void _print(Array * group, int k)
{
    for (int i = 0; i < k; ++i) {
        array::print(group[i].arr, group[i].len);
    }
}

Array * split(int * arr, int n, int size_of_segment, int & k)
{
    if (!arr || n <= 0 || size_of_segment <= 0 || n <= size_of_segment) {
        k = 0;
        return NULL;
    }

    Array * group = NULL;
    int p = n % size_of_segment;
    if (p) {
        k = n / size_of_segment + 1;
        group = new Array[k];
        for (int i = 0; i < k - 1; ++i) {
            group[i].arr = arr + size_of_segment * i;
            group[i].len = size_of_segment;
        }
        group[k-1].arr = arr + size_of_segment * (k-1);
        group[k-1].len = p;
    }
    else {
        k = n / size_of_segment;
        group = new Array[k];
        for (int i = 0; i < k; ++i) {
            group[i].arr = arr + size_of_segment * i;
            group[i].len = size_of_segment;
        }
    }
//    _print(group, k);
    return group;
}

void insert_sort(int * arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int t = arr[i], j = i - 1;
        for (; j >= 0 && arr[j] > arr[i]; --j)
            ;;
        for (int k = i - 1; k > j; --k) {
            arr[k+1] = arr[k];
        }
        arr[j+1] = t;
    }
}

int _it(int * tree, int k, Array * group, int s)
{
    if (s >= k) {
        return s - k;
    }

    int L = _it(tree, k, group, s * 2);
    int R = _it(tree, k, group, s * 2 + 1);
    int winner;
    if (group[L].get() < group[R].get()) {
        winner = L;
        tree[s] = R;
    }
    else {
        winner = R;
        tree[s] = L;
    }
    return winner;
}

int _init_tree(int * tree, int k, Array * group)
{
    return _it(tree, k, group, 1);
}

void k_merge(Array * group, const int k, int * output)
{
    int * tree = new int[k];
    int winner = _init_tree(tree, k, group);

    int w = 0, MAX = std::numeric_limits<int>::max();
    int p = 0;
    while ((w = group[winner].get()) < MAX) {
        output[p++] = w;
        group[winner].next();
        int j = winner + k;
        while (j > 1) {
            int ex_loser = tree[j/2];
            if (group[winner].get() > group[ex_loser].get()) {
                tree[j/2] = winner;
                winner = ex_loser;
            }
            j /= 2;
        }
    }

    delete[] tree;
}
