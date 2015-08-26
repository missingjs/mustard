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

// customize: operator<<, operator>>, operator!=, read_hierarchy

template <typename T>
struct node
{
    T data;
    node<T> *lc, *rc;

    node(const T & t = T(), node<T> * lc = NULL, node<T> * rc = NULL)
        : data(t), lc(lc), rc(rc)
    {}

    virtual ~node()
    {
    }
};

struct ch_data
{
    char ch;
    ch_data(char ch = 0)
        : ch(ch)
    {}
};

std::istream & operator>>(std::istream & in, ch_data & c);
std::ostream & operator<<(std::ostream & out, const ch_data & c);
bool operator!=(const ch_data & c1, const ch_data & c2);

template <typename T>
void free(node<T> * root)
{
    if (root) {
        free(root->lc);
        free(root->rc);
    }
    delete root;
}

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

    CHILD_SIBLING_FORMAT    // treat as child-sibling tree

};

template <typename T, typename N>
N * read_parent_child()
{
    const char term_char = '#';

    std::queue<N*> qu;
    T parent, child;
    std::cin >> parent;
    N * root = new N(parent);
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
        N * front = qu.front();
        if (front->data != parent) {
            qu.pop();
            continue;
        }

        N * n = new N(child);
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

template <typename NODE>
NODE * _read_hierarchy_char();

template <typename T, typename N>
N * read_hierarchy()
{
    return _read_hierarchy_char<N>();
}

char _next_char(const char * & p);

template <typename NODE>
NODE * _read_hierarchy_char()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::stack<NODE*> stk;
    const char * p = input_line.c_str();
    NODE *lc = NULL, *rc = NULL, *nd = NULL;

    stk.push(NULL);
    while (*p) {
        char ch = _next_char(p);
        if (!ch) {
            break;
        }
        switch (ch) {
            case '(':
                stk.push(NULL);
                break;
            case ',':
                lc = stk.top();
                stk.pop();
                stk.top()->lc = lc;
                stk.push(NULL);
                break;
            case ')':
                rc = stk.top();
                stk.pop();
                stk.top()->rc = rc;
                break;
            default:
                stk.top() = new NODE(ch);
                break;
        }
    }
    return stk.top();
}

template <>
node<char> * read_hierarchy< char,node<char> >();

template <typename T, typename N>
N * _build_pre_in_order(
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

    N * n = new N(*bpre);

    n->lc = _build_pre_in_order<T,N>(
            bpre + 1, bpre + 1 + left_size, bin, p);
    n->rc = _build_pre_in_order<T,N>(
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

template <typename T, typename N>
N * read_pre_in_order()
{
    int n = 0;
    T *pre = NULL, *in = NULL;
    _read_elements_seq(n, pre, in);
    if (n == 0) {
        return NULL;
    }

    N * root = _build_pre_in_order<T,N>(pre, pre + n, in, in + n);
    delete[] pre;
    delete[] in;
    return root;
}

template <typename T, typename N>
N * _build_in_post_order(
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

    N * n = new N(*p);
    
    n->lc = _build_in_post_order<T,N>(
            bin, p, bpost, bpost + left_size);
    n->rc = _build_in_post_order<T,N>(
            p + 1, ein, bpost + left_size, epost - 1);

    return n;
}

template <typename T, typename N>
N * read_in_post_order()
{
    int n = 0;
    T *in = NULL, *post = NULL;
    _read_elements_seq(n, in, post);
    if (n == 0) {
        return NULL;
    }
    
    N * root = _build_in_post_order<T,N>(in, in + n, post, post + n);
    delete[] in;
    delete[] post;
    return root;
}

template <typename N>
void _append_child(N * parent, N * child)
{
    if (!parent->lc) {
        parent->lc = child;
    } else {
        N * n = parent->lc;
        while (n->rc) {
            n = n->rc;
        }
        n->rc = child;
    }
}

template <typename N>
N * _read_child_sibling_char()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::stack<N*> stk;
    const char * p = input_line.c_str();
    N * n = NULL;

    while (*p) {
        char ch = _next_char(p);
        if (!ch) {
            break;
        }
        switch (ch) {
            case '(':
                break;
            case ')':
            case ',':
                n = stk.top();
                stk.pop();
                _append_child(stk.top(), n);
                break;
            default:
                stk.push(new N(ch));
                break;
        }
    }
    return stk.top();
}

template <typename T, typename N>
N * read_child_sibling()
{
    return _read_child_sibling_char<N>();
}

template <typename T, typename N = node<T> >
N * read(format_type type = HIERARCHY_FORMAT)
{
    switch (type) {
        case PARENT_CHILD_FORMAT:
            return read_parent_child<T,N>();
        case HIERARCHY_FORMAT:
            return read_hierarchy<T,N>();
        case PRE_IN_ORDER_FORMAT:
            return read_pre_in_order<T,N>();
        case IN_POST_ORDER_FORMAT:
            return read_in_post_order<T,N>();
        case CHILD_SIBLING_FORMAT:
            return read_child_sibling<T,N>();
        default:
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
void print_child_sibling(node<T> * root)
{
    std::cout << root->data;
    if (root->lc) {
        node<T> * n = root->lc;
        std::cout << '(';
        print_child_sibling(n);
        n = n->rc;
        while (n) {
            std::cout << ',';
            print_child_sibling(n);
            n = n->rc;
        }
        std::cout << ')';
    }
}

template <typename T>
void print(node<T> * root, format_type type = HIERARCHY_FORMAT)
{
    if (!root) {
        std::cout << "[empty bitree]\n";
        return;
    }

    switch (type) {
        case PARENT_CHILD_FORMAT:
            print_parent_child(root);
            break;
        case HIERARCHY_FORMAT:
            print_hierarchy(root);
            break;
        case CHILD_SIBLING_FORMAT:
            print_child_sibling(root);
            std::cout << '\n';
            break;
        default:
            std::cerr << "unknown format: " << type << '\n';
            std::exit(1);
    }
}

#include "impl/__thrd_bitree.h"

} // namespace ::mustard::bitree

} // namespace ::mustard

#endif  // ifndef MUSTARD_BITREE_H

