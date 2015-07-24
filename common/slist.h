#ifndef MUSTARD_SLIST_H
#define MUSTARD_SLIST_H 1

#include <iostream>

namespace mustard {

namespace slist {

template <typename T>
struct node
{
    T data;
    node<T> * next;

    node(const T & t = T())
        : data(t), next(0) 
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

    node<T> * head = NULL;
    node<T> * last = NULL;
    for (int i = 0; i < len; ++i) {
        T data;
        std::cin >> data;
        node<T> * n = new node<T>(data);
        if (last == NULL) {
            head = last = n;
        } else {
            last->next = n;
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
    return head;
}

} // namespace ::mustard::slist

} // namespace ::mustard

#endif
