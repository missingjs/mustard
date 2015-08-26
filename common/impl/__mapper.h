template <typename T>
mapper<T>::mapper()
    : _arr()
{}

template <typename T>
mapper<T>::~mapper()
{}

template <typename T>
int mapper<T>::add(const T & t)
{
    int i = _find(t);
    if (i < 0) {
        i = (int) _arr.size();
        _arr.push_back(t);
    }
    return i;
}

template <typename T>
int mapper<T>::get(const T & t) const
{
    return _find(t);
}

template <typename T>
int mapper<T>::size() const
{
    return (int) _arr.size();
}

template <typename T>
int mapper<T>::_find(const T & t) const
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
std::vector<T> mapper<T>::all() const
{
    return _arr;
}

