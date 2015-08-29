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
        return const_cast<struct_t*>(&_mx);
    }

protected:

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


template <>
class directed_graph_adaptor< matrix::common_matrix<bool> > :
    public directed_network_adaptor<bool, matrix::common_matrix<bool> >
{
    typedef directed_network_adaptor< bool, matrix::common_matrix<bool> > base_t;

public:

    directed_graph_adaptor(int n, bool iv)
        : base_t(n, iv)
    {}

    void set(int i, int j)
    {
        base_t::set(i, j, true);
    }

};


template <>
class undirected_graph_adaptor< matrix::symmetric_matrix<bool> > :
    public undirected_network_adaptor<bool, matrix::symmetric_matrix<bool> >
{
    typedef undirected_network_adaptor<bool, matrix::symmetric_matrix<bool> >  base_t;

public:

    undirected_graph_adaptor(int n, bool iv)
        : base_t(n, iv)
    {}

    void set(int i, int j)
    {
        base_t::set(i, j, true);
    }

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

