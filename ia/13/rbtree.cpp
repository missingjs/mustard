// @mission: Red Black Tree
#include <iostream>

#include "rbtree.def.h"
#include "common/array.h"
using namespace mustard;

int main()
{
    int len = 0;
    int * arr = array::read<int>(len);

    RBTree tree;
    for (int i = 0; i < len; ++i) {
        tree.insert(arr[i]);
    }

    tree.display();

//    int a = 0, b = len - 1, c = len/2;
//
//    tree.remove(arr[a]);
//    tree.remove(arr[b]);
//    tree.remove(arr[c]);
//
//    std::cout << "after remove " << arr[a] << ',' << arr[b] << ',' << arr[c] << '\n';

    tree.remove(100);
    tree.remove(70);

    tree.display();

    delete[] arr;
    return 0;
}

