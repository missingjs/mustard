#ifndef MUSTARD_GRAPH_H
#define MUSTARD_GRAPH_H 1

#include <limits>
#include <iostream>

#include "matrix2.h"
#include "id.h"
#include "array.h"

namespace mustard {
namespace graph {

template <
    typename V, 
    typename W,
    typename Adaptor,
    typename WeightTraits, 
    typename Identifier = id::identifier<V>
>
class generic_graph
{
public:

    typedef V vex_t;

    typedef W weight_t;

    typedef typename Adaptor::struct_t struct_t;

public:
    template <typename Iter>
    generic_graph(int n, Iter begin, Iter end);

    ~generic_graph();

    int id(const V & v) const;

    V vex(int id) const;

    void set(const V & v1, const V & v2, const W & w);

    W get(const V & v1, const V & v2) const;

    static W unconnected_value()
    {
        return WeightTraits::unconnected_value();
    }

    void remove(const V & v1, const V & v2);

    struct_t * get_structure() const;

    void display(std::ostream & out) const;

protected:

    Identifier _idtf;

    Adaptor * _adpt;

};


template <typename W>
struct numeric_weight
{
    static W initial_value()
    {
        return std::numeric_limits<W>::max();
    }

    static W unconnected_value()
    {
        return initial_value();
    }

};


template <typename W, typename S>
class directed_network_adaptor
{};


template <typename V, typename W, typename S>
class directed_network : 
    public generic_graph< V, W, 
        directed_network_adaptor<W,S>, numeric_weight<W> >
{
public:
    template <typename Iter>
    directed_network(int n, Iter begin, Iter end)
        : generic_graph< V, W, directed_network_adaptor<W,S>,
            numeric_weight<W> >(n, begin, end)
    {}
};


template <typename W, typename S>
class undirected_network_adaptor
{};


template <typename V, typename W, typename S>
class undirected_network :
    public generic_graph< V, W,
        undirected_network_adaptor<W,S>, numeric_weight<W> >
{
public:
    template <typename Iter>
    undirected_network(int n, Iter begin, Iter end)
        : generic_graph< V, W, undirected_network_adaptor<W,S>,
            numeric_weight<W> >(n, begin, end)
    {}
};

template <typename T>
struct boolean_weight
{
    static T initial_value()
    {
        return T(0);
    }

    static T unconnected_value()
    {
        return initial_value();
    }

};

template <typename S>
class directed_graph_adaptor
{};

template <typename V, typename S>
class directed_graph :
    public generic_graph< V, bool,
       directed_graph_adaptor<S>, boolean_weight<bool> >
{
    typedef generic_graph< V, bool, 
        directed_graph_adaptor<S>, boolean_weight<bool> >  base_t;

    using base_t::_adpt;
    using base_t::_idtf;

public:
    template <typename Iter>
    directed_graph(int n, Iter begin, Iter end)
        : base_t(n, begin, end)
    {}

    void set(const V & v1, const V & v2)
    {
        _adpt->set(_idtf.id(v1), _idtf.id(v2));
    }

};


template <typename S>
class undirected_graph_adaptor
{};

template <typename V, typename S>
class undirected_graph:
    public generic_graph< V, bool,
        undirected_graph_adaptor<S>, boolean_weight<bool> >
{
    typedef generic_graph< V, bool, 
        undirected_graph_adaptor<S>, boolean_weight<bool> >  base_t;

    using base_t::_adpt;
    using base_t::_idtf;

public:
    template <typename Iter>
    undirected_graph(int n, Iter begin, Iter end)
        : base_t(n, begin, end)
    {}

    void set(const V & v1, const V & v2)
    {
        _adpt->set(_idtf.id(v1), _idtf.id(v2));
    }

};


template <typename Network>
Network * read_network()
{
    typedef typename Network::vex_t vex_t;
    typedef typename Network::weight_t w_t;
    int n = 0;
    vex_t * vexes = array::read<vex_t>(n);
    
    Network * net = new Network(n, vexes, vexes + n);

    int m = 0;
    std::cin >> m;
    vex_t v1, v2;
    w_t w;
    for (int i = 0; i < m; ++i) {
        std::cin >> v1 >> v2 >> w;
        net->set(v1, v2, w);
    }

    delete[] vexes;
    return net;
}


template <typename Graph>
Graph * read_graph()
{
    typedef typename Graph::vex_t vex_t;
    int n = 0;
    vex_t * vexes = array::read<vex_t>(n);

    Graph * g = new Graph(n, vexes, vexes + n);

    int m = 0;
    std::cin >> m;
    vex_t v1, v2;
    for (int i = 0; i < m; ++i) {
        std::cin >> v1 >> v2;
        g->set(v1, v2);
    }

    delete[] vexes;
    return g;
}


#include "impl/__adj_matrix.h"
#include "impl/__adj_list.h"
#include "impl/__orth_list.h"
#include "impl/__adj_multilist.h"


template <typename V, typename W, typename AD, typename WT, typename I>
    template <typename Iter>
generic_graph<V,W,AD,WT,I>::generic_graph(int n, Iter begin, Iter end)
    : _idtf(begin, end), _adpt(new AD(n, WT::initial_value()))
{
}

template <typename V, typename W, typename AD, typename WT, typename I>
generic_graph<V,W,AD,WT,I>::~generic_graph()
{
    delete _adpt;
}

template <typename V, typename W, typename AD, typename WT, typename I>
int generic_graph<V,W,AD,WT,I>::id(const V & v) const
{
    return _idtf.id(v);
}

template <typename V, typename W, typename AD, typename WT, typename I>
V generic_graph<V,W,AD,WT,I>::vex(int id) const
{
    return _idtf.element(id);
}

template <typename V, typename W, typename AD, typename WT, typename I>
void generic_graph<V,W,AD,WT,I>::set(const V & v1, const V & v2, const W & w)
{
    _adpt->set(_idtf.id(v1), _idtf.id(v2), w);
}

template <typename V, typename W, typename AD, typename WT, typename I>
W generic_graph<V,W,AD,WT,I>::get(const V & v1, const V & v2) const
{
    return _adpt->get(_idtf.id(v1), _idtf.id(v2));
}

template <typename V, typename W, typename AD, typename WT, typename I>
void generic_graph<V,W,AD,WT,I>::remove(const V & v1, const V & v2)
{
    _adpt->remove(_idtf.id(v1), _idtf.id(v2));
}

template <typename V, typename W, typename AD, typename WT, typename I>
typename generic_graph<V,W,AD,WT,I>::struct_t * 
generic_graph<V,W,AD,WT,I>::get_structure() const
{
    return _adpt->get_structure();
}

template <typename V, typename W, typename AD, typename WT, typename I>
void generic_graph<V,W,AD,WT,I>::display(std::ostream & out) const
{
    std::vector<V> elements = _idtf.all();
    for (size_t i = 0; i < elements.size(); ++i) {
        out << '[' << i << ']' << elements[i] << ' ';
    }
    out << '\n';
    _adpt->display(out);
}

}  // namespace ::mustard::graph
}  // namespace ::mustard

#endif  // ifndef MUSTARD_GRAPH_H

