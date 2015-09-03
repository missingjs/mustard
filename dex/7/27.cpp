// @mission: 判别无向图中给定两顶点之间是否存在一条长度为k的简单路径
#include "27.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    char a, b;
    int k = 0;
    std::cin >> a >> b >> k;
    find_len_of_path(g, a, b, k);
    delete g;
    return 0;
}
