template <typename T>
    template <typename Iter>
_graph_base<T>::_graph_base(Iter begin, Iter end)
    : _mp()
{
    for (Iter i(begin); i != end; ++i) {
        _mp.add(*i);
    }
}

template <typename T>
_graph_base<T>::_graph_base()
{
}

template <typename T>
    template <typename Iter>
graph_adj_matrix<T>::graph_adj_matrix(Iter begin, Iter end)
    : _graph_base<T>(begin, end), _mx(end-begin, end-begin)
{}

template <typename T>
graph_adj_matrix<T>::~graph_adj_matrix()
{
}

template <typename T>
void graph_adj_matrix<T>::add(const T & t1, const T & t2)
{
    int i = _mp.get(t1), j = _mp.get(t2);
    _mx[i][j] = 1;
}

template <typename T>
int _graph_base<T>::get(const T & t) const
{
    return _mp.get(t);
}

template <typename T>
int graph_adj_matrix<T>::get(const T & t1, const T & t2) const
{
    int i = _mp.get(t1), j = _mp.get(t2);
    return _mx[i][j];
}

template <typename T>
void ugraph_adj_matrix<T>::add(const T & t1, const T & t2)
{
    graph_adj_matrix<T>::add(t1, t2);
    graph_adj_matrix<T>::add(t2, t1);
}

template <typename T>
int ugraph_adj_matrix<T>::get(const T & t1, const T & t2) const
{
    int a = graph_adj_matrix<T>::get(t1, t2);
    int b = graph_adj_matrix<T>::get(t2, t1);
    return (a || b) ? 1 : 0;
}

template <typename T>
void graph_adj_matrix<T>::display(std::ostream & out) const
{
    std::vector<T> vex = _mp.all();
    typename std::vector<T>::iterator i = vex.begin(), e = vex.end();
    for (; i != e; ++i) {
        out << *i << ' ';
    }
    out << '\n';
    matrix::print(_mx);
}

template <typename T, typename G>
G * _read_adj_matrix_graph()
{
    int len = 0;                                                           
    T * arr = array::read<T>(len);                                            
    if (!arr || len == 0) {                                                
        return NULL;                                                       
    }                                                                      
                                                                           
    G * g = new G(arr, arr + len);     
                                                                           
    int num_e = 0;                                                         
    std::cin >> num_e;                                                     
                                                                           
    T t1, t2;                                                              
    for (int i = 0; i < num_e; ++i) {                                      
        std::cin >> t1 >> t2;                                              
        g->add(t1, t2);                                                    
    }                                                                      
                                                                           
    return g;
}

template <typename T>
graph_adj_matrix<T> * graph_adj_matrix<T>::read()
{
    return _read_adj_matrix_graph<T, graph_adj_matrix<T> >();
}

template <typename T>
ugraph_adj_matrix<T> * ugraph_adj_matrix<T>::read()
{
    return _read_adj_matrix_graph<T, ugraph_adj_matrix<T> >();
}
