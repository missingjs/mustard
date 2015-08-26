template <typename T>
const T sparse_matrix<T>::_default_value = T();

template <typename T>
sparse_matrix<T>::sparse_matrix(int row, int col)
    : _data(), _row(row), _col(col)
{
}

template <typename T>
sparse_matrix<T>::~sparse_matrix()
{
}

template <typename T>
sparse_matrix<T>::sparse_matrix(const sparse_matrix<T> & m)
    : _data(_data), _row(m._row), _col(m._col)
{
}

template <typename T>
sparse_matrix<T> & sparse_matrix<T>::operator =(const sparse_matrix<T> & m)
{
    sparse_matrix<T> tmp(m);
    swap(tmp);
    return (*this);
}

template <typename T>
void sparse_matrix<T>::swap(sparse_matrix<T> & m)
{
    _data.swap(m._data);
    std::swap(_row, m._row);
    std::swap(_col, m._col);
}

template <typename T>
sparse_matrix<T>::_elem_proxy::_elem_proxy(
        int row, int col, sparse_matrix<T> & mx)
    : _row(row), _col(col), _mx(mx)
{
}

template <typename T>
sparse_matrix<T>::_elem_proxy::_elem_proxy(
        const _elem_proxy & e)
    : _row(e._row), _col(e._col), _mx(e._mx)
{
}

template <typename T>
typename sparse_matrix<T>::_elem_proxy &
sparse_matrix<T>::_elem_proxy::operator =(const T & d)
{
    _mx.set(_row, _col, d);
}

template <typename T>
sparse_matrix<T>::_elem_proxy::operator T() const
{
    return _mx.get(_row, _col);
}

template <typename T>
sparse_matrix<T>::_matrix_row::_matrix_row(int row, sparse_matrix<T> & mx)
    : _row(row), _mx(mx)
{
}

template <typename T>
sparse_matrix<T>::_matrix_row::_matrix_row(const _matrix_row & r)
    : _row(r._row), _mx(r._mx)
{
}

template <typename T>
typename sparse_matrix<T>::_elem_proxy
sparse_matrix<T>::_matrix_row::operator [](int i)
{
    return _elem_proxy(_row, i, _mx);
}

template <typename T>
sparse_matrix<T>::_const_matrix_row::_const_matrix_row(
        int row, const sparse_matrix<T> & mx)
    : _row(row), _mx(mx)
{
}

template <typename T>
sparse_matrix<T>::_const_matrix_row::_const_matrix_row(
        const _const_matrix_row & r)
    : _row(r._row), _mx(r._mx)
{
}

template <typename T>
T sparse_matrix<T>::_const_matrix_row::operator [](int i) const
{
    return _mx.get(_row, i);
}

template <typename T>
const typename sparse_matrix<T>::tup *
sparse_matrix<T>::find(int row, int col) const
{
    typename std::vector<tup>::const_iterator i = _data.begin(), e = _data.end();
    for (; i != e; ++i) {
        if (i->r == row && i->c == col) {
            return &(*i);
        }
    }
    return NULL;
}

template <typename T>
void sparse_matrix<T>::set(int row, int col, const T & t)
{
    tup * p = const_cast<tup*>(find(row, col));
    if (p) {
        p->d = t;
    } else {
        _data.push_back(tup(row, col, t));
    }
}

template <typename T>
T sparse_matrix<T>::get(int row, int col) const
{
    const tup * p = find(row, col);
    return p ? p->d : _default_value;
}

template <typename T>
std::istream & operator >>(std::istream & in, sparse_matrix<T> & m)
{
    int ne = 0, row, col;
    T t;

    in >> ne;
    for (int i = 0; i < ne; ++i) {
        in >> row >> col >> t;
        m[row][col] = t;
    }
}

template <typename T>
void sparse_matrix<T>::get_elements(
        std::vector<tup> & elements) const
{
    elements.insert(elements.end(), _data.begin(), _data.end());
}

template <typename T>
std::ostream & operator <<(std::ostream & out, const sparse_matrix<T> & m)
{
    typedef typename sparse_matrix<T>::tup tup_t;
    std::vector<tup_t> elements;
    m.get_elements(elements);
    out << m.row() << ' ' << m.col() << '\n' << m.num_elements() << '\n';
    for (size_t i = 0; i < elements.size(); ++i) {
        out << elements[i].r << ',' << elements[i].c << ',' << elements[i].d << '\n';
    }
}

template <typename T>
sparse_matrix<T> * read_sparse_matrix()
{
    int row, col;
    std::cin >> row >> col;
    sparse_matrix<T> * m = new sparse_matrix<T>(row, col);
    std::cin >> (*m);
    return m;
}

template <typename T>
void print(const sparse_matrix<T> * m)
{
    print(*m);
}

template <typename T>
void print(const sparse_matrix<T> & m)
{
    std::cout << m;
}

template <typename T>
void print_as_common(const sparse_matrix<T> * m)
{
    print_as_common(*m);
}

template <typename T>
void print_as_common(const sparse_matrix<T> & m)
{
    for (int i = 0; i < m.row(); ++i) {
        for (int j = 0; j < m.col(); ++j) {
            std::cout << m[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

template <typename T>
typename sparse_matrix<T>::_matrix_row
sparse_matrix<T>::operator [](int row)
{
    return _matrix_row(row, *this);
}

template <typename T>
typename sparse_matrix<T>::_const_matrix_row
sparse_matrix<T>::operator [](int row) const
{
    return _const_matrix_row(row, *this);
}

