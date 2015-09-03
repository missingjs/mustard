// @mission: 以邻接矩阵方式存储的有向图G中求点i到顶点j的不含回路的、长度为k的路径数
#include "29.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    char i, j;
    int k = -1;
    std::cin >> i >> j >> k;
    int r = find_num_of_path(g, i, j, k);
    std::cout << '[' << r << ']' << '\n';
    delete g;
    return 0;
}

