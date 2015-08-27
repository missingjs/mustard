template <typename T>
symmetric_matrix<T>::symmetric_matrix(int n)
    : _n(n), _data(new T[n*(n+1)/2])
{}

template <typename T>
symmetric_matrix<T>::~symmetric_matrix()
{
    delete[] _data;
}

template <typename T>
symmetric_matrix<T>::symmetric_matrix(
        const symmetric_matrix<T> & m)
    : _n(m._n), _data(NULL)
{
    int total = _n * (_n + 1) / 2;
    _data = new T[total];
    for (int i = 0; i < total; ++i) {
        _data[i] = m._data[i];
    }
}

template <typename T>
symmetric_matrix<T> & 
symmetric_matrix<T>::operator=(
        const symmetric_matrix<T> & m)
{
    symmetric_matrix<T> temp(m);
    swap(temp);
    return (*this);
}

template <typename T>
void symmetric_matrix<T>::swap(symmetric_matrix<T> & m)
{
    std::swap(_n, m._n);
    std::swap(_data, m._data);
}

