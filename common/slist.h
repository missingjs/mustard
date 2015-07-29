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
    node<T> * t = head;
    while (t) {
        node<T> * p = t;
        t = t->next;
        delete p;
        if (t == head) {
            break;
        }
    }
}

template <typename T>
void print(node<T> * n)
{
    std::cout << '[';
    node<T> * p = n;
    while (p) {
        std::cout << p->data;
        if (p->next && p->next != n) {
            std::cout << ", ";
        }
        p = p->next;
        if (p == n) {
            break;
        }
    }
    std::cout << "]\n";
}

template <typename T>
node<T> * clone(node<T> * n)
{
    node<T> *head = NULL, *last = NULL;
    for (node<T> * p = n; p; ) {
        node<T> * new_n = new node<T>(p->data);
        if (last == NULL) {
            head = last = new_n;
        } else {
            last->next = new_n;
            last = new_n;
        }

        p = p->next;
        if (p == n) { // circular list
            last->next = head; // clone as circular list too
            break;
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

template <typename T>
node<T> * from_array(const T * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return NULL;
    }

    node<T> head, *tail = &head;
    for (int i = 0; i < len; ++i) {
        node<T> * n = new node<T>(arr[i]);
        tail->next = n;
        tail = n;
    }

    return head.next;
}

template <typename T>
node<T> * make_circular(node<T> * h)
{
    if (h == NULL) {
        return NULL;
    }

    node<T> * p = h;
    for (; p->next != NULL; p = p->next)
        ;;

    p->next = h;

    return p;
}

template <typename T>
node<T> * de_circular(node<T> * tail)
{
    if (tail == NULL) {
        return NULL;
    }

    node<T> * head = tail->next;
    tail->next = NULL;
    return head;
}

} // namespace ::mustard::slist

} // namespace ::mustard

#endif
