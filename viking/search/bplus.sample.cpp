#include "bplus.def.h"
#include <queue>
#include <map>
#include <iostream>

bool _is_leaf(bp_node * p)
{
    return !p->ptr[0];
}

bool _find(bp_node * root, int k, bp_node * & q, int & i)
{
    bp_node * p = root;
    int j = 0;
    while (true) {
        for (j = 0; j < p->n; ++j) {
            if (p->key[j] >= k) {
                break;
            }
        }
        if (_is_leaf(p)) {
            break;
        } else {
            p = p->ptr[j];
        }
    }

    q = p;
    i = j;
    return q->key[i] == k;
}

void _update_key(bp_node * p, int key, int new_key)
{
    if (!p) {
        return;
    }

    int max = p->key[p->n-1];
    for (int i = 0; i < p->n; ++i) {
        if (p->key[i] == key) {
            p->key[i] = new_key;
            break;
        }
    }
    if (p->key[p->n-1] != max) {
        _update_key(p->parent, max, p->key[p->n-1]);
    }
}

void _insert_key(bp_node * p, int i, int k)
{
    int max = p->key[p->n-1];
    for (int j = p->n - 1; j >= i; --j) {
        p->key[j+1] = p->key[j];
    }
    p->key[i] = k;
    ++p->n;

    if (p->key[p->n-1] != max) {
        _update_key(p->parent, max, p->key[p->n-1]);
    }
}

void _split(bp_node * p, bp_node * & n1, bp_node * & n2)
{
    n1 = p;
    n2 = new bp_node;
    n2->key[0] = p->key[2];
    n2->key[1] = p->key[3];
    n1->n = n2->n = 2;
    if (_is_leaf(p)) {
        n2->next = n1->next;
        n1->next = n2;
    } else {
        n2->ptr[0] = n1->ptr[2];
        n2->ptr[1] = n1->ptr[3];
        n2->ptr[0]->parent = n2->ptr[1]->parent = n2;
    }
}

void _insert_child(bp_node * p, bp_node * n1, bp_node * n2)
{
    int i = 0;
    int max = n2->max_key();
    for (; i < p->n && p->key[i] < max; ++i)
        ;;
    for (int j = p->n; j > i; --j) {
        p->key[j] = p->key[j-1];
        p->ptr[j] = p->ptr[j-1];
    }
    p->key[i] = n1->max_key();
    p->key[i+1] = max;
    p->ptr[i] = n1;
    p->ptr[i+1] = n2;
    n1->parent = n2->parent = p;
    if (p->n) {
        ++p->n;
    } else {
        p->n = 2;
    }
}

void _insert(bp_tree * tree, int k)
{
    if (!tree->root) {
        bp_node * r = new bp_node;
        r->n = 1;
        r->key[0] = k;
        tree->root = tree->sqt = r;
        return;
    }

    bp_node * p = NULL;
    int i = -1;

    if (_find(tree->root, k, p, i)) {
        return;
    }

    _insert_key(p, i, k);

    while (p->n == 4) {
        bp_node *n1 = NULL, *n2 = NULL;
        bp_node * parent = p->parent;
        _split(p, n1, n2);

        if (!parent) {
            tree->root = parent = new bp_node;
        }

        _insert_child(parent, n1, n2);

        p = parent;
    }
}

void _bp_print(bp_node * root)
{
    for (int i = 0; i < root->n; ++i) {
        std::cout << root->key[i];
        if (i < root->n - 1) {
            std::cout << '|';
        }
    }
    if (!_is_leaf(root)) {
        std::cout << '(';
        for (int i = 0; i < root->n - 1; ++i) {
            _bp_print(root->ptr[i]);
            std::cout << ',';
        }
        _bp_print(root->ptr[root->n-1]);
        std::cout << ')';
    }
}

bp_tree * create_b_plus(int * arr, int n)
{
    if (!arr || n <= 0) {
        return NULL;
    }

    bp_tree * tree = new bp_tree;
    for (int i = 0; i < n; ++i) {
        _insert(tree, arr[i]);
    }
    return tree;
}

void bp_print(bp_tree * tree)
{
    if (tree && tree->root) {
        _bp_print(tree->root);
    }
    std::cout << '\n';
    if (tree && tree->sqt) {
        bp_node * p = tree->sqt;
        for (; p; p = p->next) {
            for (int i = 0; i < p->n; ++i) {
                std::cout << p->key[i];
                if (i < p->n - 1) {
                    std::cout << ',';
                }
            }
            if (p->next) {
                std::cout << " -> ";
            }
        }
    }
    std::cout << '\n';
}

void bp_print_2(bp_tree * tree)
{
    if (!tree || !tree->root) {
        return;
    }

    std::map<bp_node*, int> LM;
    std::queue<bp_node*> qu;
    qu.push(tree->root);
    LM[tree->root] = 1;
    int cur_level = 0;

    while (!qu.empty()) {
        bp_node * f = qu.front();
        qu.pop();
        int L = LM[f];
        if (L != cur_level) {
            std::cout << '\n';
            cur_level = L;
        }
        for (int i = 0; i < f->n; ++i) {
            std::cout << f->key[i];
            if (i < f->n - 1) {
                std::cout << ',';
            }
            if (f->ptr[i]) {
                qu.push(f->ptr[i]);
                LM[f->ptr[i]] = L + 1;
            }
        }
        std::cout << "   ";
    }
    std::cout << '\n';
}

void _bp_free(bp_node * root)
{
    if (root) {
        for (int i = 0; i < root->n; ++i) {
            _bp_free(root->ptr[i]);
        }
        delete root;
    }
}

void bp_free(bp_tree * tree)
{
    if (tree) {
        _bp_free(tree->root);
    }
    delete tree;
}

void _rm_from_bplus(bp_tree * tree, int k)
{
    bp_node * p = NULL;
    int i = -1;

    if (!_find(tree->root, k, p, i)) {
        return;
    }

    // TODO
    int max = p->max_key();
    _remove_key(p, i, k);
    if (p->max_key() != max) {
        _update_key(p->parent, max, p->max_key());
    }

    while (p->n == 1) {
        // TODO
        if ()
        _process_weak_node(p);
        p = p->parent;
    }
}

void remove_from_b_plus(bp_tree * tree, int * arr, int n)
{
    if (!tree || !arr) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        // TODO
        _rm_from_bplus(tree, arr[i]);
    }
}
