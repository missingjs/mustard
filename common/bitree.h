#ifndef MUSTARD_BITREE_H
#define MUSTARD_BITREE_H 1

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

namespace mustard {

namespace bitree {

template <typename T>
struct node
{
    T data;
    node<T> *lc, *rc;

    node(const T & t = T(), node<T> * lc = NULL, node<T> * rc = NULL)
        : data(t), lc(lc), rc(rc)
    {}

    ~node()
    {
        delete lc;
        delete rc;
    }
};

enum format_type
{
    PLAIN_TEXT_FORMAT,   // just data, output use


    PARENT_CHILD_FORMAT, 
    /*
       eg:
            A
            B A L
            C A R

       represents a tree, root is 'A', left child is 'B', and right child is 'C'
     */

    HIERARCHY_FORMAT,    // eg: A(B(C,D),)   (no blank)


    PRE_IN_ORDER_FORMAT,    // num-nodes, pre-order and in-order sequence

    IN_POST_ORDER_FORMAT,   // num-nodes, in-order and post-order sequence

};

template <typename T>
node<T> * read_parent_child()
{
    const char term_char = '#';

    std::queue<node<T>*> qu;
    T parent, child;
    std::cin >> parent;
    node<T> * root = new node<T>(parent);
    qu.push(root);

    char side;
    std::cin >> child >> parent >> side;
    if (std::cin.eof()) {
        return root;
    }
    if (side == term_char) {
        return root;
    }

    while (!qu.empty()) {
        node<T> * front = qu.front();
        if (front->data != parent) {
            qu.pop();
            continue;
        }

        node<T> * n = new node<T>(child);
        if (side == 'L' || side == 'l') {
            front->lc = n;
        } else if (side == 'R' || side == 'r') {
            front->rc = n;
        } else {
            std::cerr << "error child flag: " << side << '\n';
            std::exit(2);
        }
        qu.push(n);
        std::cin >> child >> parent >> side;
        if (std::cin.eof()) {
            break;
        }
    }

    return root;
}

template <typename T>
node<T> * read_hierarchy()
{
    std::cerr << "unsupported element type in read_hierarchy()\n";
    return NULL;
}

template <>
node<char> * read_hierarchy();

template <typename T>
node<T> * _build_pre_in_order(
        const T * bpre, const T * epre, 
        const T * bin, const T * ein)
{
    if (bpre == epre) {
        return NULL;
    }

    const T * p = bin;
    while (*p != *bpre) {
        ++p;
    }

    int left_size = p - bin;

    node<T> * n = new node<T>(*bpre);

    n->lc = _build_pre_in_order(
            bpre + 1, bpre + 1 + left_size, bin, p);
    n->rc = _build_pre_in_order(
            bpre + 1 + left_size, epre, p + 1, ein);

    return n;
}

template <typename T>
void _read_elements_seq(int & n, T * & s1, T * & s2)
{
    std::cin >> n;
    if (n <= 0) {
        n = 0;
        return;
    }

    s1 = new T[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> s1[i];
    }

    s2 = new T[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> s2[i];
    }
}

template <typename T>
node<T> * read_pre_in_order()
{
    int n = 0;
    T *pre = NULL, *in = NULL;
    _read_elements_seq(n, pre, in);
    if (n == 0) {
        return NULL;
    }

    node<T> * root = _build_pre_in_order(pre, pre + n, in, in + n);
    delete[] pre;
    delete[] in;
    return root;
}

template <typename T>
node<T> * _build_in_post_order(
        const T * bin, const T * ein,
        const T * bpost, const T * epost)
{
    if (bin == ein) {
        return NULL;
    }

    const T * p = bin;
    while (*p != *(epost-1)) {
        ++p;
    }

    int left_size = p - bin;

    node<T> * n = new node<T>(*p);
    
    n->lc = _build_in_post_order(
            bin, p, bpost, bpost + left_size);
    n->rc = _build_in_post_order(
            p + 1, ein, bpost + left_size, epost - 1);

    return n;
}

template <typename T>
node<T> * read_in_post_order()
{
    int n = 0;
    T *in = NULL, *post = NULL;
    _read_elements_seq(n, in, post);
    if (n == 0) {
        return NULL;
    }
    
    node<T> * root = _build_in_post_order(in, in + n, post, post + n);
    delete[] in;
    delete[] post;
    return root;
}

template <typename T>
node<T> * read(format_type type = HIERARCHY_FORMAT)
{
    if (type == PARENT_CHILD_FORMAT) {
        return read_parent_child<T>();
    } else if (type == HIERARCHY_FORMAT) {
        return read_hierarchy<T>();
    } else if (type == PRE_IN_ORDER_FORMAT) {
        return read_pre_in_order<T>();
    } else if (type == IN_POST_ORDER_FORMAT) {
        return read_in_post_order<T>();
    } else {
        std::cerr << "unknown format: " << type << '\n';
        std::exit(1);
    }
}

template <typename T>
void print_parent_child(node<T> * root)
{
    std::cout << root->data << '\n';

    std::queue<node<T>*> qu;
    qu.push(root);
    while (!qu.empty()) {
        node<T> * front = qu.front();
        qu.pop();
        if (front->lc) {
            std::cout << front->lc->data << ' ' << front->data << " L\n";
            qu.push(front->lc);
        }
        if (front->rc) {
            std::cout << front->rc->data << ' ' << front->data << " R\n";
            qu.push(front->rc);
        }
    }
}

template <typename T>
void _print_hier(node<T> * root)
{
    if (root) {
        std::cout << root->data;
        if (root->lc || root->rc) {
            std::cout << '(';
            _print_hier(root->lc);
            std::cout << ',';
            _print_hier(root->rc);
            std::cout << ')';
        }
    }
}

template <typename T>
void print_hierarchy(node<T> * root)
{
    _print_hier(root);
    std::cout << '\n';
}

template <typename T>
void print(node<T> * root, format_type type = HIERARCHY_FORMAT)
{
    if (!root) {
        std::cout << "[empty bitree]\n";
        return;
    }

    if (type == PARENT_CHILD_FORMAT) {
        print_parent_child(root);
    } else if (type == HIERARCHY_FORMAT) {
        print_hierarchy(root);
    } else {
        std::cerr << "unknown format: " << type << '\n';
        std::exit(1);
    }
}

#include "__thrd_bitree.h"

} // namespace ::mustard::bitree

} // namespace ::mustard

#endif  // ifndef MUSTARD_BITREE_H
