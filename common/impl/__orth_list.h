template <typename W>
class orthogonal_list
{
public:

    struct arc_node
    {
        W   weight;
        int begin, end;
        arc_node *bnext, *enext;

        arc_node(const W & w = W(), int b = -1, int e = -1)
            : weight(w), begin(b), end(e)
              , bnext(NULL), enext(NULL)
        {}
    };

    struct head_node
    {
        arc_node *blist, *elist;

        head_node()
            : blist(NULL), elist(NULL)
        {}
    };

public:

    orthogonal_list(int n);

    ~orthogonal_list();

    int size() const
    {
        return _size;
    }

    void set(int i, int j, const W & w);

    bool get(int i, int j, W & value) const;

    void remove(int i, int j);

private:

    arc_node * _find(int i, int j) const;

public:

    head_node * _head_list;

    int _size;

};


template <typename W>
class directed_network_adaptor< W, orthogonal_list<W> >
{
public:

    typedef orthogonal_list<W> struct_t;

    directed_network_adaptor(int n, const W & w)
        : _orz(n), _unconnect(w)
    {}

    void set(int i, int j, const W & w)
    {
        _orz.set(i, j, w);
    }

    W get(int i, int j) const
    {
        W w;
        return _orz.get(i,j,w) ? w : _unconnect;
    }

    void remove(int i, int j)
    {
        _orz.remove(i, j);
    }

    void display(std::ostream & out) const;

    struct_t * get_structure() const
    {
        return & _orz;
    }

protected:

    struct_t  _orz;

    W _unconnect;

};


template <typename W>
orthogonal_list<W>::orthogonal_list(int n)
    : _head_list(new head_node[n]), _size(n)
{}

template <typename W>
orthogonal_list<W>::~orthogonal_list()
{
    arc_node *p = NULL, *t = NULL;
    for (int i = 0; i < _size; ++i) {
        p = _head_list[i].blist;
        while (p) {
            t = p;
            p = p->bnext;
            delete t;
        }
    }
    delete[] _head_list;
}

template <typename W>
void orthogonal_list<W>::set(int i, int j, const W & w)
{
    arc_node * n = _find(i, j);
    if (n) {
        n->weight = w;
        return;
    }

    n = new arc_node(w, i, j);
    n->bnext = _head_list[i].blist;
    _head_list[i].blist = n;

    n->enext = _head_list[j].elist;
    _head_list[j].elist = n;
}

template <typename W>
bool orthogonal_list<W>::get(int i, int j, W & value) const
{
    arc_node * n = _find(i, j);
    if (n) {
        value = n->weight;
    }
    return !!n;
}

template <typename W>
void orthogonal_list<W>::remove(int i, int j)
{
    arc_node *p = _head_list[i].blist, *last = NULL;
    if (p->end == j) {
        _head_list[i].blist = p->bnext;
    } else {
        do {
            last = p;
            p = p->bnext;
        } while (p && p->end != j); 

        if (!p) {
            return;
        }

        last->bnext = p->bnext;
    }

    arc_node * q = _head_list[j].elist;
    if (q == p) {
        _head_list[j].elist = q->enext;
    } else {
        do {
            last = q;
            q = q->enext;
        } while (q && q != p);

        last->enext = q->enext;
    }

    delete p;
}

template <typename W>
typename orthogonal_list<W>::arc_node *
orthogonal_list<W>::_find(int i, int j) const
{
    arc_node * p = _head_list[i].blist;
    while (p && p->end != j) {
        p = p->bnext;
    }
    return p;
}

template <typename W>
void directed_network_adaptor< W, orthogonal_list<W> >::
display(std::ostream & out) const
{
    typedef typename orthogonal_list<W>::arc_node arc_t;

    int size = _orz.size();
    int total = size * size;
    W * w = new W[total];
    for (int i = 0; i < total; ++i) {
        w[i] = _unconnect;
    }

    for (int i = 0; i < size; ++i) {
        arc_t * p = _orz._head_list[i].blist;
        while (p) {
            w[p->begin * size + p->end] = p->weight;
            p = p->bnext;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            W & v = w[i * size + j];
            if (v != _unconnect) {
                std::cout << v << ' ';
            } else {
                std::cout << '*' << ' ';
            }
        }
        std::cout << '\n';
    }
}

