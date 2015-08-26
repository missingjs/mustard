template <typename T, typename N>
    template <typename Iter>
graph_adj_list<T,N>::graph_adj_list(Iter begin, Iter end)
    : _graph_base<T>(begin, end), _heads(new N*[_mp.size()])
{
    memset(_heads, 0, sizeof(N*) * _mp.size());
}

template <typename T, typename N>
graph_adj_list<T,N>::~graph_adj_list()
{
    for (int i = 0; i < _mp.size(); ++i) {
        N * p = _heads[i];
        while (p) {
            N * t = p;
            p = p->next;
            delete t;
        }
    }
    delete[] _heads;
}

template <typename T, typename N>
void graph_adj_list<T,N>::add(const T & t1, const T & t2)
{
    int i = index(t1), j = index(t2);
    N * n = new N(j);
    n->next = _heads[i];
    _heads[i] = n;
}

template <typename T, typename N>
int graph_adj_list<T,N>::get(const T & t1, const T & t2) const
{
    int i = index(t1), j = index(t2);
    N * p = _heads[i];
    while (p && p->index != j) {
        p = p->next;
    }
    return p ? 1 : 0;
}

template <typename T, typename N>
void graph_adj_list<T,N>::display(std::ostream & out) const
{
    for (int i = 0; i < vex_count(); ++i) {
        out << element(i) << ' ' << i << ' ';
        if (!_heads[i]) {
            out << "^\n";
        } else {
            out << "->";
            N * p = _heads[i];
            while (p) {
                out << ' ' << p->index;
                p = p->next;
            }
            out << '\n';
        }
    }
}

template <typename T, typename N>
graph_adj_list<T,N> * graph_adj_list<T,N>::read()
{
    return _read_graph<T, graph_adj_list<T,N> >();
}

template <typename T, typename N>
void ugraph_adj_list<T,N>::add(const T & t1, const T & t2)
{
    graph_adj_list<T,N>::add(t1, t2);
    graph_adj_list<T,N>::add(t2, t1);
}

template <typename T, typename N>
int ugraph_adj_list<T,N>::get(const T & t1, const T & t2) const
{
    int a = graph_adj_list<T,N>::get(t1, t2);
    int b = graph_adj_list<T,N>::get(t2, t1);
    return (a || b) ? 1 : 0;
}

template <typename T, typename N>
ugraph_adj_list<T,N> * ugraph_adj_list<T,N>::read()
{
    return _read_graph<T, ugraph_adj_list<T,N> >();
}

