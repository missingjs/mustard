template <typename T>
struct adj_matrix
{
    adj_matrix(int n, const T & t);

    ~adj_matrix()
    {}

    void set(int i, int j, const T & t);

    T get(int i, int j) const;

    void remove(int i, int j);

    void display(std::ostream & out) const;

    matrix::common_matrix<T> _mx;

    T _unconnect;

};

template <typename T>
adj_matrix<T>::adj_matrix(int n, const T & t)
    : _mx(n, n), _unconnect(t)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            _mx[i][j] = t;
        }
    }
}

template <typename T>
void adj_matrix<T>::set(int i, int j, const T & t)
{
    _mx[i][j] = t;
}

template <typename T>
T adj_matrix<T>::get(int i, int j) const
{
    return _mx[i][j];
}

template <typename T>
void adj_matrix<T>::remove(int i, int j)
{
    _mx[i][j] = _unconnect;
}

template <typename T>
void adj_matrix<T>::display(std::ostream & out) const
{
    for (int i = 0; i < _mx.row(); ++i) {
        for (int j = 0; j < _mx.col(); ++j) {
            if (_mx[i][j] != _unconnect) {
                out << _mx[i][j] << ' ';
            } else {
                out << '*' << ' ';
            }
        }
        out << '\n';
    }
}

