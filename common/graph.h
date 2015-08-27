#ifndef MUSTARD_GRAPH_H
#define MUSTARD_GRAPH_H 1

#include <limits>
#include <iostream>

#include "matrix2.h"
#include "id.h"
#include "array.h"

namespace mustard {
namespace graph {

#include "impl/__graph_network.h"

template <
    typename V, 
    typename W,
    typename Structure,
    typename WeightTraits, 
    typename Identifier = id::identifier<V>
>
class generic_graph
{
public:

    typedef V vex_t;

    typedef W weight_t;


public:
    template <typename Iter>
    generic_graph(int n, Iter begin, Iter end);

    ~generic_graph();

    int id(const V & v) const;

    V vex(int id) const;

    void set(const V & v1, const V & v2, const W & w);

    W get(const V & v1, const V & v2) const;

    void remove(const V & v1, const V & v2);

    Structure * get_structure() const;

    void display(std::ostream & out) const;

private:

    Identifier _idtf;

    Structure * _struct;

};


template <typename V, typename W, typename S>
class directed_network : public generic_graph< V, W, S, numeric_weight<W> >
{
public:
    template <typename Iter>
    directed_network(int n, Iter begin, Iter end)
        : generic_graph< V,W,S,numeric_weight<W> >(n, begin, end)
    {}
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


#include "impl/__adj_matrix.h"


template <typename V, typename W, typename S, typename WT, typename I>
    template <typename Iter>
generic_graph<V,W,S,WT,I>::generic_graph(int n, Iter begin, Iter end)
    : _idtf(begin, end), _struct(new S(n, WT::initial_value()))
{
}

template <typename V, typename W, typename S, typename WT, typename I>
generic_graph<V,W,S,WT,I>::~generic_graph()
{
    delete _struct;
}

template <typename V, typename W, typename S, typename WT, typename I>
int generic_graph<V,W,S,WT,I>::id(const V & v) const
{
    return _idtf.id(v);
}

template <typename V, typename W, typename S, typename WT, typename I>
V generic_graph<V,W,S,WT,I>::vex(int id) const
{
    return _idtf.element(id);
}

template <typename V, typename W, typename S, typename WT, typename I>
void generic_graph<V,W,S,WT,I>::set(const V & v1, const V & v2, const W & w)
{
    _struct->set(_idtf.id(v1), _idtf.id(v2), w);
}

template <typename V, typename W, typename S, typename WT, typename I>
W generic_graph<V,W,S,WT,I>::get(const V & v1, const V & v2) const
{
    return _struct->get(_idtf.id(v1), _idtf.id(v2));
}

template <typename V, typename W, typename S, typename WT, typename I>
void generic_graph<V,W,S,WT,I>::remove(const V & v1, const V & v2)
{
    _struct->remove(_idtf.id(v1), _idtf.id(v2));
}

template <typename V, typename W, typename S, typename WT, typename I>
S * generic_graph<V,W,S,WT,I>::get_structure() const
{
    return _struct;
}

template <typename V, typename W, typename S, typename WT, typename I>
void generic_graph<V,W,S,WT,I>::display(std::ostream & out) const
{
    std::vector<V> elements = _idtf.all();
    for (size_t i = 0; i < elements.size(); ++i) {
        out << '[' << i << ']' << elements[i] << ' ';
    }
    out << '\n';
    _struct->display(out);
}

}  // namespace ::mustard::graph
}  // namespace ::mustard

#endif  // ifndef MUSTARD_GRAPH_H

