#ifndef LOSE_TREE_DEF_H
#define LOSE_TREE_DEF_H 1

#include <limits>
#include <cstddef>

struct Array
{
    int * arr;
    int len, cur;
    Array(int * arr = NULL, int len = 0)
        : arr(arr), len(len), cur(0)
    {}

    int get() const
    {
        return cur < len ? arr[cur] : std::numeric_limits<int>::max();
    }

    int next()
    {
        if (cur < len) {
            ++cur;
        }
        return get();
    }
};

Array * split(int * arr, int n, int size_of_segment, int & k);

void insert_sort(int * arr, int n);

void k_merge(Array * group, int k, int * output);

#endif

