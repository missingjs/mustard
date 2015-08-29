// @mission: 判断无向图G是否是一棵树
#include "13.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();

    bool r = is_tree(g);
    std::cout << std::boolalpha << r << '\n';

    delete g;
    return 0;
}
