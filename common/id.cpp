#include <algorithm>

#include "id.h"

namespace mustard {
namespace id {

identifier<int>::identifier()
    : _arr(NULL), _elements()
{
    init_arr();
}

void identifier<int>::init_arr()
{
    _arr = new int[arr_size];
    for (int i = 0; i < arr_size; ++i) {
        _arr[i] = -1;
    }
}

identifier<int>::~identifier()
{
    delete[] _arr;
}

int identifier<int>::add(int e)
{
    if (_arr[e] == -1) {
        _arr[e] = (int)_elements.size();
        _elements.push_back(e);
    }
    return _arr[e];
}

int identifier<int>::id(int e) const
{
    return _arr[e];
}

int identifier<int>::size() const
{
    return (int) _elements.size();
}

struct _identifier_cmp
{
private:
    int * _arr;
public:
    _identifier_cmp(int * _arr)
        : _arr(_arr)
    {}
    bool operator()(int i, int j)
    {
        return _arr[i] < _arr[j];
    }
};

std::vector<int> identifier<int>::all() const
{
    std::vector<int> v;
    for (int i = 0; i < arr_size; ++i) {
        if (_arr[i] >= 0) {
            v.push_back(i);
        }
    }
    std::sort(v.begin(), v.end(), _identifier_cmp(_arr));
    return v;
}

int identifier<int>::element(int i) const
{
    return _elements[i];
}

std::vector<char> identifier<char>::all() const
{
    std::vector<int> v = identifier<int>::all();
    std::vector<char> v2(v.begin(), v.end());
    return v2;
}

}  // namespace ::mustard::graph
}  // namespace ::mustard

