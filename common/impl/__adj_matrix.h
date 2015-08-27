template <typename W>
class directed_network_adaptor<W, matrix::common_matrix<W> >
{
public:

    typedef matrix::common_matrix<W> struct_t;

    directed_network_adaptor(int n, const W & t);

    ~directed_network_adaptor()
    {}

    void set(int i, int j, const W & t);

    W get(int i, int j) const;

    void remove(int i, int j);

    void display(std::ostream & out) const;

    struct_t * get_structure() const
    {
        return &_mx;
    }

private:

    struct_t   _mx;

    W  _unconnect;

};

template <typename W>
directed_network_adaptor<W, matrix::common_matrix<W> >::
    directed_network_adaptor(int n, const W & t)
    : _mx(n, n), _unconnect(t)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            _mx[i][j] = t;
        }
    }
}

template <typename W>
void directed_network_adaptor<W, matrix::common_matrix<W> >::
set(int i, int j, const W & t)
{
    _mx[i][j] = t;
}

template <typename W>
W directed_network_adaptor<W, matrix::common_matrix<W> >::
get(int i, int j) const
{
    return _mx[i][j];
}

template <typename W>
void directed_network_adaptor<W, matrix::common_matrix<W> >::
remove(int i, int j)
{
    _mx[i][j] = _unconnect;
}

template <typename W>
void directed_network_adaptor<W, matrix::common_matrix<W> >::
display(std::ostream & out) const
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

