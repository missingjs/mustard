#include "b-tree.def.h"
#include <iostream>

bool _search(b_node * root, int k, b_node * & p, int & i)
{
    int j = 1;
    for (; j <= root->n && root->key[j] < k; ++j)
        ;;

    if (root->key[j] == k) {
        i = j;
        p = root;
        return true;
    } else if (!root->ptr[j-1]) {
        i = j;
        p = root;
        return false;
    } else {
        return _search(root->ptr[j-1], k, p, i);
    }
}

void _insert_key(b_node * p, int k, int i)
{
    for (int j = p->n; j >= i; --j) {
        p->key[j+1] = p->key[j];
    }
    p->key[i] = k;
}

void _insert_child(b_node * p, int k, b_node * left, b_node * right)
{
    int j = 1;
    for (; j <= p->n && p->key[j] < k; ++j)
        ;;

    for (int m = p->n; m >= j; --m) {
        p->key[m+1] = p->key[m];
        p->ptr[m+1] = p->ptr[m];
    }

    p->key[j] = k;
    p->ptr[j] = right;
    p->ptr[j-1] = left;
}

void _split(b_node * p, int & k, b_node * & left, b_node * & right)
{
    k = p->key[2];

    right = new b_node;
    right->n = 1;
    right->key[1] = p->key[3];
    right->ptr[0] = p->ptr[2];
    right->ptr[1] = p->ptr[3];

    left = p;
    left->n = 1;
}

b_node * _insert(b_node * root, int k)
{
    b_node * p = NULL;
    int index = 0;

    if (_search(root, k, p, index)) {
        return root;
    }

    _insert_key(p, k, index);
    while (p->n == 3) {
        b_node *parent = p->parent, *left, *right;
        int key = 0;
        _split(p, key, left, right);
        if (!parent) {
            parent = new b_node;
            root = parent;
        }
        _insert_child(parent, key, left, right);
        p = parent;
    }

    return root;
}

b_node * create_b_tree(int * arr ,int n)
{
    if (!arr || n <= 0) {
        return NULL;
    }

    b_node * root = new b_node;
    root->key[1] = arr[0];
    root->n = 1;

    for (int i = 1; i < n; ++i) {
        root = _insert(root, arr[i]);
    }

    return root;
}

void b_print(b_node * btree)
{
    if (!btree) {
        return;
    }

    std::cout << btree->key[1];
    if (btree->n == 2) {
        std::cout << '|' << btree->key[2];
    }

    if (btree->ptr[0]) {
        std::cout << '(';
        b_print(btree->ptr[0]);
        for (int i = 1; i <= btree->n; ++i) {
            std::cout << ',';
            b_print(btree->ptr[i]);
        }
        std::cout << ')';
    }
}

void b_free(b_node * root)
{
    for (int i = 0; i <= root->n; ++i) {
        b_free(root->ptr[i]);
    }
    delete root;
}
