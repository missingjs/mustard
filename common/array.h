#ifndef MUSTARD_ARRAY_H
#define MUSTARD_ARRAY_H 1

#include <iostream>

namespace mustard {

template <typename T>
T * array_read(int size, int capacity)
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
T * array_read(int len)
{
    return array_read<T>(len, len);
}

template <typename T>
T * array_n_read(int & len)
{
    if (!(std::cin >> len)) {
        return NULL;
    }
    if (len < 0) {
        return NULL;
    }
    return array_read<T>(len);
}

template <typename T>
void array_free(T * arr)
{
    delete[] arr;
}

template <typename T>
void array_print(const T * arr, int len)
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


namespace array {

template <typename T>
T * read(int size, int capacity)
{
    return ::mustard::array_read<T>(size, capacity);
}

template<typename T>
T * read(int len)
{
    return ::mustard::array_read<T>(len);
}

template <typename T>
T * n_read(int & len)
{
    return ::mustard::array_n_read<T>(len);
}

template <typename T>
void free(T * arr)
{
    ::mustard::array_free(arr);
}

template <typename T>
void print(const T * arr, int len)
{
    ::mustard::array_print(arr, len);
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
