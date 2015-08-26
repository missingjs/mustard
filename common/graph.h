#ifndef MUSTARD_GRAPH_H
#define MUSTARD_GRAPH_H 1

#include <vector>
#include <iostream>
#include <algorithm>

#include "matrix2.h"
#include "array.h"

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
    std::vector<T> all() const;

private:
    int _find(const T & t) const;

private:
    std::vector<T> _arr;
};

template <>
class mapper<int>
{
    const int arr_size = 256;
public:
    mapper();
    ~mapper();
    int add(int e); 
    int get(int e) const;
    int size() const;
    std::vector<int> all() const;
private:
    int * _arr;
    int _size;
};

template <>
class mapper<char> : public mapper<int>
{
public:
    std::vector<char> all() const;
};

template <typename T>
class _graph_base
{
public:
    template <typename Iter>
    _graph_base(Iter begin, Iter end);
    ~_graph_base();

    int get(const T & t) const;

protected:
    mapper<T> _mp;
};

template <typename T>
class graph_adj_matrix : public _graph_base<T>
{
public:
    template <typename Iter>
    graph_adj_matrix(Iter begin, Iter end);
    ~graph_adj_matrix();

    void add(const T & t1, const T & t2);

    int get(const T & t1, const T & t2) const;

    void display(std::ostream & out) const;

    void print() const
    {
        display(std::cout);
    }

    static graph_adj_matrix<T> * read();

private:
    matrix::common_matrix<int> _mx;
};

template <typename T>
class ugraph_adj_matrix : public graph_adj_matrix<T>
{
public:
    template <typename Iter>
    ugraph_adj_matrix(Iter begin, Iter end)
        : graph_adj_matrix<T>(begin, end)
    {}

    void add(const T & t1, const T & t2);

    int get(const T & t1, const T & t2) const;

    static ugraph_adj_matrix<T> * read();

};

template <typename T>
class graph_adj_list : public _graph_base<T>
{
public:
    template <typename Iter>
    graph_adj_list(Iter begin, Iter end);
    ~graph_adj_list();

    void add(const T & t1, const T & t2);

    int get(const T & t1, const T & t2) const;

    void display(std::ostream & out) const;

    void print() const
    {
        display(std::cout);
    }

    static graph_adj_list<T> * read();
};


#include "impl/__mapper.h"
#include "impl/__g_adj_matrix.h"

}  // namespace ::mustard::graph
}  // namespace ::mustard

#endif  // ifndef MUSTARD_GRAPH_H
