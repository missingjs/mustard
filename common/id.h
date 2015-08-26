#ifndef MUSTARD_ID_H
#define MUSTARD_ID_H 1

#include <vector>

namespace mustard {
namespace id {

template <typename T>
class identifier 
{
public:

    identifier();

    ~identifier();

    int add(const T & t);

    int id(const T & t) const;

    int size() const;

    std::vector<T> all() const;

    T element(int i) const;

private:

    std::vector<T> _arr;

};

template <>
class identifier<int>
{
    const int arr_size = 256;

public:

    identifier();

    ~identifier();

    int add(int e);

    int id(int e) const;

    int size() const;

    std::vector<int> all() const;

    int element(int i) const;

private:

    int * _arr;

    std::vector<int> _elements;

};

template <>
class identifier<char> : public identifier<int>
{
public:
    std::vector<char> all() const;
};

template <typename T>
identifier<T>::identifier()
    : _arr()
{}

template <typename T>
identifier<T>::~identifier()
{}

template <typename T>
int identifier<T>::add(const T & t)
{
    int i = id(t);
    if (i < 0) {
        i = (int) _arr.size();
        _arr.push_back(t);
    }
    return i;
}

template <typename T>
int identifier<T>::size() const
{
    return (int) _arr.size();
}

template <typename T>
int identifier<T>::id(const T & t) const
{
    int i = 0;
    for (; i < (int) _arr.size(); ++i) {
        if (t == _arr[i]) {
            break;
        }
    }
    return i < (int) _arr.size() ? i : -1;
}

template <typename T>
std::vector<T> identifier<T>::all() const
{
    return _arr;
}

template <typename T>
T identifier<T>::element(int i) const
{
    return _arr[i];
}

} // namespace ::mustard::id
} // namespace ::mustard

#endif  // ifndef MUSTARD_ID_H

