#ifndef MUSTARD_GRAPH_H
#define MUSTARD_GRAPH_H 1

#include <vector>
#include "matrix2.h"

namespace mustard {
namespace graph {

enum graph_type {
    DG,   // directed graph
    DN,   // directed net
    UDG,  // undirected graph
    UDN   // undirected net
};

template <typename T>
class mapper
{
public:
    mapper();
    ~mapper();
    int add(const T & t);
    int get(const T & t) const;
    int size() const;

private:
    int _find(const T & t) const;

private:
    std::vector<T> _arr;
};

template <>
class mapper<int>
{
public:
    mapper();
    ~mapper();
    int add(int e); 
    int get(int e) const;
    int size() const;
private:
    int * _arr;
    int _size;
};

template <>
class mapper<char> : public mapper<int>
{};

#include "impl/__mapper.h"

}  // namespace ::mustard::graph
}  // namespace ::mustard

#endif  // ifndef MUSTARD_GRAPH_H
