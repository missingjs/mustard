#ifndef MUSTARD_ARRAY_H
#define MUSTARD_ARRAY_H 1

#include <iostream>

namespace mustard {

namespace array {

template <typename T>
T * read_n(int size, int capacity)
{
    if (capacity < size) {
        capacity = size;
    }

    if (size < 0) {
        return NULL;
    }

    T * arr = new T[capacity];
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    return arr;
}

template <typename T>
T * read_n(int len)
{
    return read_n<T>(len, len);
}

template <typename T>
T * read(int & len)
{
    if (!(std::cin >> len)) {
        return NULL;
    }
    if (len < 0) {
        return NULL;
    }
    return ::mustard::array::read_n<T>(len);
}

template <typename T>
void free(T * arr)
{
    delete[] arr;
}

template <typename T>
void print(const T * arr, int len)
{
    if (arr == NULL || len <= 0) {
        std::cout << "[]\n";
        return;
    }

    std::cout << '[';
    int before_last = len - 1;
    for (int i = 0; i < before_last; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[before_last] << "]\n";
}

template <typename T>
T * clone(const T * arr, int len)
{
    if (arr == NULL) {
        return NULL;
    }

    T * new_arr = new T[len];
    for (int i = 0; i < len; ++i) {
        new_arr[i] = arr[i];
    }

    return new_arr;
}

} // namespace ::mustard::array

} // namespace ::mustard

#endif
