template <typename T>
common_matrix<T>::common_matrix(int row, int col)
    : _row(row), _col(col), _data(new T[row * col])
{
}

template <typename T>
common_matrix<T>::~common_matrix()
{
    delete[] _data;
}

template <typename T>
common_matrix<T>::common_matrix(const common_matrix<T> & m)
    : _row(m._row), _col(m._col), _data(new T[_row * _col])
{
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _col; ++j) {
            _data[i * _row + j] = m._data[i * _row + j];
        }
    }
}

template <typename T>
common_matrix<T> & common_matrix<T>::operator= (const common_matrix<T> & m)
{
    common_matrix<T> tmp(m);
    swap(tmp);
    return (*this);
}

template <typename T>
void common_matrix<T>::swap(common_matrix<T> & m)
{
    std::swap(_row, m._row);
    std::swap(_col, m._col);
    std::swap(_data, m._data);
}

template <typename T>
common_matrix<T>::_matrix_row::_matrix_row(int row, common_matrix<T> & mx)
    : _row(row), _mx(mx)
{
}

template <typename T>
common_matrix<T>::_matrix_row::_matrix_row(const _matrix_row & r)
    : _row(r._row), _mx(r._mx)
{
}

template <typename T>
T & common_matrix<T>::_matrix_row::operator[] (int col)
{
    return _mx.d(_row, col);
}

template <typename T>
common_matrix<T>::_const_matrix_row::_const_matrix_row(
        int row, const common_matrix<T> & mx)
    : _row(row), _mx(mx)
{
}

template <typename T>
common_matrix<T>::_const_matrix_row::_const_matrix_row(
        const _const_matrix_row & r)
    : _row(r._row), _mx(r._mx)
{
}

template <typename T>
T common_matrix<T>::_const_matrix_row::operator[] (int col) const
{
    return _mx.d(_row, col);
}

template <typename T>
typename common_matrix<T>::_matrix_row
common_matrix<T>::operator[] (int row)
{
    return _matrix_row(row, *this);
}

template <typename T>
typename common_matrix<T>::_const_matrix_row 
common_matrix<T>::operator[] (int row) const
{
    return _const_matrix_row(row, *this);
}

template <typename T>
T & common_matrix<T>::d(int r, int c)
{
    return _data[r * _col + c];
}

template <typename T>
T common_matrix<T>::d(int r, int c) const
{
    return const_cast<common_matrix<T>*>(this)->d(r,c);
}

template <typename T>
std::istream & operator>> (std::istream & in, common_matrix<T> & m)
{
    for (int i = 0; i < m.row(); ++i) {
        for (int j = 0; j < m.col(); ++j) {
            in >> m[i][j];
        }
    }
}

template <typename T>
std::ostream & operator<< (std::ostream & out, const common_matrix<T> & m)
{
    for (int i = 0; i < m.row(); ++i) {
        for (int j = 0; j < m.col(); ++j) {
            out << m[i][j] << ' ';
        }
        out << '\n';
    }
}

template <typename T>
common_matrix<T> * read_common_matrix()
{
    int row = 0, col = 0;
    std::cin >> row >> col;
    common_matrix<T> * m = new common_matrix<T>(row, col);
    std::cin >> (*m);
    return m;
}

template <typename T>
void print(const common_matrix<T> * m)
{
    print(*m);
}

template <typename T>
void print(const common_matrix<T> & m)
{
    std::cout << m;
}

