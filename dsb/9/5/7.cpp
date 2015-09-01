// @mission: 判断有向图是否存在回路
#include "7.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    bool t = test_loop_exists(g);
    std::cout << std::boolalpha << t << '\n';
    delete g;
    return 0;
}

