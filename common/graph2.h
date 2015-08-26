#ifndef MUSTARD_GRAPH_H
#define MUSTARD_GRAPH_H 1

namespace mustard {
namespace graph {

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
    template <typename Iter>
    generic_graph(int n, Iter begin, Iter end);

    ~generic_graph();

    int id(const V & v) const;

    V vex(int id) const;

    void set(const V & v1, const V & v2, const W & w);

    W get(const V & v1, const V & v2) const;

    void remove(const V & v1, const V & v2);

    Structure * get_structure() const;

private:

    Identifier _idtf;

    Structure * _struct;

};

}  // namespace ::mustard::graph
}  // namespace ::mustard

#endif
