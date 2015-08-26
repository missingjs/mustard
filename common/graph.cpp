#include "graph.h"

namespace mustard {
namespace graph {

mapper<int>::mapper()
    : _arr(new int[256]), _size(0)
{
    for (int i = 0; i < 256; ++i) {
        _arr[i] = -1;
    }
}

mapper<int>::~mapper()
{
    delete[] _arr;
}

int mapper<int>::add(int e)
{
    if (_arr[e] == -1) {
        _arr[e] = _size++;
    }
    return _arr[e];
}

int mapper<int>::get(int e) const
{
    return _arr[e];
}

int mapper<int>::size() const
{
    return _size;
}

}  // namespace ::mustard::graph
}  // namespace ::mustard
