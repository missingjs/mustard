// @mission: 实现Floyd算法，打印所有最短路径
#include "floyd.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    floyd_print_all_path(g);
    delete g;
    return 0;
}
