template <typename T>
class adj_list
{
public:

    struct node
    {
        T      weight;
        int    adj;
        node * next;

        node(const T & t = T())
            : weight(t), adj(-1), next(NULL)
        {}
    };

    adj_list(int n);

    ~adj_list();

    void set(int i, int j, const T & t);

    bool get(int i, int j, T & value) const;

    void remove(int i, int j);

    int size() const
    {
        return _size;
    }


private:

    node * _find(int i, int j) const;


public:

    node * _heads;

    int    _size;

};


template <typename W>
class directed_network_adaptor< W, adj_list<W> >
{
public:

    typedef adj_list<W> struct_t;

    directed_network_adaptor(int n, const W & w)
        : _a(n), _unconnect(w)
    {}

    ~directed_network_adaptor() {}

    void set(int i, int j, const W & w)
    {
        _a.set(i, j, w);
    }

    W get(int i, int j) const
    {
        W w;
        return _a.get(i,j,w) ? w : _unconnect;
    }

    void remove(int i, int j)
    {
        _a.remove(i,j);
    }

    void display(std::ostream & out) const;

    struct_t * get_structure() const
    {
        return & _a;
    }

private:

    struct_t _a;

    W  _unconnect;

};


template <typename T>
adj_list<T>::adj_list(int n)
    : _heads(new node[n]), _size(n)
{}

template <typename T>
adj_list<T>::~adj_list()
{
    for (int i = 0; i < _size; ++i) {
        node * p = _heads[i];
        while (p) {
            node * t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] _heads;
}

template <typename T>
void adj_list<T>::set(int i, int j, const T & t)
{
    node * n = _find(i,j);
    if (n) {
        n->weight = t;
    } else {
        n = new node(t);
        node->adj = j;
        node->next = _heads[i];
        _heads[i] = node;
    }
}

template <typename T>
bool adj_list<T>::get(int i, int j, T & value) const
{
    node * n = _find(i,j);
    if (n) {
        value = n->weight;
    }
    return !!n;
}

template <typename T>
void adj_list<T>::remove(int i, int j)
{
    if (!_heads[i]) {
        return;
    }

    if (_heads[i]->adj == j) {
        node * p = _heads[i];
        _heads[i] = p->next;
        delete p;
    } else {
        node *last = _heads[i], *p = last->next;
        while (p && p->adj != j) {
            last = p;
            p = p->next;
        }
        if (p) {
            last->next = p->next;
            delete p;
        }
    }
}

template <typename T>
typename adj_list<T>::node *
adj_list<T>::_find(int i, int j) const
{
    node * p = _heads[i];
    while (p && p->adj != j) {
        p = p->next;
    }
    return p;
}

template <typename W>
void directed_network_adaptor<W, adj_list<W> >::
display(std::ostream & out) const
{
    typedef typename adj_list<W>::node node_t;
    for (int i = 0; i < _a.size(); ++i) {
        out << i << ' ';
        if (!_a._heads[i]) {
            out << '^' << '\n';
        } else {
            out << "-> ";
            node_t * p = _a._heads[i];
            while (p) {
                out << '(' << p->adj << ',' << p->weight << ')';
                if (p->next) {
                    out << ", ";
                }
                p = p->next;
            }
            out << '\n';
        }
    }
}

