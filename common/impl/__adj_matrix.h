template <typename W>
class directed_network_adaptor<W, matrix::common_matrix<W> >
{
public:

    typedef matrix::common_matrix<W> struct_t;

    directed_network_adaptor(int n, const W & t);

    ~directed_network_adaptor()
    {}

    void set(int i, int j, const W & t)
    {
        _mx[i][j] = t;
    }

    W get(int i, int j) const
    {
        return _mx[i][j];
    }

    void remove(int i, int j)
    {
        _mx[i][j] = _unconnect;
    }

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
class undirected_network_adaptor<W, matrix::symmetric_matrix<W> >
{
public:

    typedef matrix::symmetric_matrix<W> struct_t;

    undirected_network_adaptor(int n, const W & w);

    ~undirected_network_adaptor() {}

    void set(int i, int j, const W & w)
    {
        _mx[i][j] = w;
    }

    W get(int i, int j) const
    {
        return _mx[i][j];
    }

    void remove(int i, int j)
    {
        _mx[i][j] = _unconnect;
    }

    struct_t * get_structure() const
    {
        return & _mx;
    }

    void display(std::ostream & out) const;

private:

    struct_t  _mx;

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

template <typename W>
undirected_network_adaptor<W, matrix::symmetric_matrix<W> >:: 
    undirected_network_adaptor(int n, const W & t)
    : _mx(n), _unconnect(t)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            _mx[i][j] = t;
        }   
    }   
}

template <typename W>
void undirected_network_adaptor<W, matrix::symmetric_matrix<W> >:: 
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

