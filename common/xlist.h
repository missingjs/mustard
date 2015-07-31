#ifndef MUSTARD_XLIST_H
#define MUSTARD_XLIST_H 1

#include <iostream>

namespace mustard {

namespace xlist {

template <typename T>
T * _xor(T * a, T * b)
{
    long La = reinterpret_cast<long>(static_cast<void*>(a));
    long Lb = reinterpret_cast<long>(static_cast<void*>(b));
    return static_cast<T*>(reinterpret_cast<void*>(La ^ Lb));
}

template <typename T>
struct node
{
    typedef node<T> node_type;

    T           data;
    node_type * ptr;

    node<T>(const T & t = T(), node_type * L = NULL, node_type * R = NULL) :
        data(t), ptr(_xor(L, R))
    {}
};

template <typename T>
struct linked_list
{
    node<T>  * left;
    node<T>  * right;

    linked_list<T>() :
        left(NULL), right(NULL)
    {}
};

template <typename T>
linked_list<T> * read()
{
    int size = 0;
    std::cin >> size;

    if (size < 0) {
        size = 0;
    }

    linked_list<T> * head = new linked_list<T>();
    for (int i = 0; i < size; ++i) {
        int data;
        std::cin >> data;
        node<T> * n = new node<T>(data);
        if (head->right == NULL) {
            head->left = n;
        } else {
            node<T> * tail = head->right;
            tail->ptr = _xor(_xor(tail->ptr, (node<T>*)NULL), n);
            n->ptr = _xor(tail, (node<T>*)NULL);
        }
        head->right = n;
    }

    return head;
}

template <typename T>
void free(linked_list<T> * head)
{
    if (head == NULL) {
        return;
    }

    node<T> *p = head->left, *last = NULL;
    while (p) {
        node<T> * t = p;
        p = _xor(p->ptr, last);
        last = t;
        delete t;
    }

    delete head;
}

template <typename T>
void print(linked_list<T> * head)
{
    std::cout << '[';

    if (head == NULL) {
        return;
    }

    node<T> *p = head->left, *last = NULL;
    while (p) {
        std::cout << p->data;
        if (p != head->right) {
            std::cout << ", ";
        }
        node<T> * t = p;
        p = _xor(p->ptr, last);
        last = t;
    }

    std::cout << "]\n";
}

} // namespace ::mustard::xlist

} // namespace ::mustard

#endif
