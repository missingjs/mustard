#ifndef MUSTARD_DLIST_H
#define MUSTARD_DLIST_H 1

#include <iostream>

namespace mustard {

namespace dlist {

template <typename T>
struct node
{
    T data;
    node<T> * prev;
    node<T> * next;

    node(const T & t = T())
        : data(t), prev(0), next(0)
    {}
};

template <typename T>
node<T> * read()
{
    int len = 0;
    if (!(std::cin >> len)) {
        return NULL;
    }
    if (len < 0) {
        return NULL;
    }

    node<T> *head = NULL, *last = NULL;
    for (int i = 0; i < len; ++i) {
        T data;
        std::cin >> data;
        node<T> * n = new node<T>(data);
        if (last == NULL) {
            head = last = n;
        } else {
            last->next = n;
            n->prev = last;
            last = n;
        }
    }

    return head;
}

template <typename T>
void free(node<T> * head)
{
    while (head) {
        node<T> * p = head;
        head = head->next;
        delete p;
    }
}

template <typename T>
void print(node<T> * n)
{
    std::cout << '[';
    node<T> * p = n;
    while (p) {
        std::cout << p->data;
        if (p->next) {
            std::cout << ", ";
        }
        p = p->next;
    }
    std::cout << "]\n";
}

template <typename T>
node<T> * clone(node<T> * n)
{
    node<T> *head = NULL, *last = NULL;
    for (node<T> * p = n; p; p = p->next) {
        node<T> * new_n = new node<T>(p->data);
        if (last == NULL) {
            head = last = new_n;
        } else {
            last->next = new_n;
            new_n->prev = last;
            last = new_n;
        }
    }
    return head;
}

template <typename T>
node<T> * add_head(node<T> * n)
{
    node<T> * head = new node<T>();
    head->next = n;
    n->prev = head;
    return head;
}

template <typename T>
node<T> * from_array(const T * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return NULL;
    }

    node<T> head, *tail = &head;

    for (int i = 0; i < len; ++i) {
        node<T> * n = new node<T>(arr[i]);
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    head.next->prev = NULL;
    return head.next;
}

} // namespace ::mustard::dlist

} // namespace ::mustard

#endif
