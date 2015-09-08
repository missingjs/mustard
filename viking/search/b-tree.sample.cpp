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
    ++p->n;
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

    left->parent = right->parent = p;

    ++p->n;
}

void _split(b_node * p, int & k, b_node * & left, b_node * & right)
{
    k = p->key[2];

    right = new b_node;
    right->n = 1;
    right->key[1] = p->key[3];
    right->ptr[0] = p->ptr[2];
    right->ptr[1] = p->ptr[3];
    if (right->ptr[0]) {
        right->ptr[0]->parent = right->ptr[1]->parent = right;
    }

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
    if (!root) {
        return;
    }
    for (int i = 0; i <= root->n; ++i) {
        b_free(root->ptr[i]);
    }
    delete root;
}

int _index_of_child(b_node * p)
{
    b_node * parent = p->parent;
    for (int i = 0; i <= parent->n; ++i) {
        if (parent->ptr[i] == p) {
            return i;
        }
    }
    return -1;
}

void _deal_empty_node(b_node * p)
{
    int i = _index_of_child(p);
    b_node * parent = p->parent;
    
    if (i < parent->n) {  // has right sibling
        b_node * rsib = parent->ptr[i+1];
        if (rsib->n > 1) {
            p->n = 1;
            p->key[1] = parent->key[i+1]; // parent key down
            p->ptr[1] = rsib->ptr[0];     // move right sibling's left child to p
            if (p->ptr[1]) {
                p->ptr[1]->parent = p;
            }
            parent->key[i+1] = rsib->key[1];  // right sibling's left key up
            rsib->key[1] = rsib->key[2];
            rsib->ptr[0] = rsib->ptr[1];
            rsib->ptr[1] = rsib->ptr[2];
            --rsib->n;
        } else {  // merge
            p->key[1] = parent->key[i+1];   // parent key down to p
            --parent->n;
            p->key[2] = rsib->key[1];       // right sibling's key (only one) to p
            p->n = 2;
            p->ptr[1] = rsib->ptr[0];
            p->ptr[2] = rsib->ptr[1];
            if (p->ptr[1]) {  // if right sibling has child, must be two
                p->ptr[1]->parent = p->ptr[2]->parent = p;
            }
            delete rsib;
        }
    } else {  // no right sibling, so choose left sibling
        b_node * Lsib = parent->ptr[i-1];
        if (Lsib->n > 1) {
            p->n = 1;
            p->key[1] = parent->key[i];    // parent key down to p
            p->ptr[1] = p->ptr[0];         // 
            p->ptr[0] = Lsib->ptr[Lsib->n];  // left sibling's right child to p
            if (p->ptr[0]) {
                p->ptr[0]->parent = p;
            }
            parent->key[i] = Lsib->key[Lsib->n];
            --Lsib->n;
        } else {
            Lsib->key[2] = parent->key[i];  // parent key down to left child
            --parent->n;
            ++Lsib->n;
            if (p->ptr[0]) {
                p->ptr[0]->parent = Lsib;
            }
            Lsib->ptr[2] = p->ptr[0];
            delete p;
        }
    }
}

b_node * _most_left(b_node * p)
{
    b_node * t = p;
    while (t->ptr[0]) {
        t = t->ptr[0];
    }
    return t;
}

b_node * _most_right(b_node * p)
{
    b_node * t = p;
    while (t->ptr[t->n]) {
        t = t->ptr[t->n];
    }
    return t;
}

bool _is_base(b_node * p)
{
    return !(p->ptr[0]);
}

void _del_element(b_node * p, int i)
{
    for (int j = i; j < p->n; ++j) {
        p->key[j] = p->key[j+1];
    }
    --p->n;
}

b_node * _rm_e(b_node * root, int k)
{
    b_node * p = NULL;
    int i = -1;

    if (!_search(root, k, p, i)) {
        return root;
    }

    if (!_is_base(p)) {  // not the lowest level
        if (i < p->n) {  // use min in right child to replace
            b_node * t = _most_left(p->ptr[i]);
            p->key[i] = t->key[0];
            p = t;
            i = 0;
        } else {         // use max in left child to replace
            b_node * t = _most_right(p->ptr[i-1]);
            p->key[i] = t->key[t->n];
            p = t;
            i = t->n;
        }
    }

    _del_element(p, i);

    if (p->n >= 1) {
        return root;
    }

    if (p == root) {
        delete root;
        return NULL;
    }

    while (true) {
        _deal_empty_node(p);
        p = p->parent;
        if (p->n) {
            break;
        } else if (p == root) {
            p = root->ptr[0];
            delete root;
            return p;
        }
    }

    return root;
}

b_node * remove_element(b_node * root, int * arr, int n)
{
    if (!root || !arr) {
        return NULL;
    }

    b_node * r = root;
    for (int i = 0; i < n; ++i) {
        r = _rm_e(r, arr[i]);
    }
    return r;
}


