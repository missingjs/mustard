// @mission: 参见10.png
#include "10.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    char root = get_root(g);
    std::cout << "root: " << root << '\n';
    delete g;
    return 0;
}
