#include "graph.h"

namespace mustard {
namespace graph {

mapper<int>::mapper()
    : _arr(new int[arr_size]), _size(0)
{
    for (int i = 0; i < arr_size; ++i) {
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

struct _mapper_cmp
{
private:
    int * _arr;
public:
    _mapper_cmp(int * _arr)
        : _arr(_arr)
    {}
    bool operator()(int i, int j)
    {
        return _arr[i] < _arr[j];
    }
};

std::vector<int> mapper<int>::all() const
{
    std::vector<int> v;
    for (int i = 0; i < arr_size; ++i) {
        if (_arr[i] >= 0) {
            v.push_back(i);
        }
    }
    std::sort(v.begin(), v.end(), _mapper_cmp(_arr));
    return v;
}

std::vector<char> mapper<char>::all() const
{
    std::vector<int> v = mapper<int>::all();
    std::vector<char> v2(v.begin(), v.end());
    return v2;
}

}  // namespace ::mustard::graph
}  // namespace ::mustard
