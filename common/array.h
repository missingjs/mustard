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
void array_free(T * arr)
{
    delete[] arr;
}

template <typename T>
void array_print(T * arr, int len)
{
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

} // namespace mustard

#endif
