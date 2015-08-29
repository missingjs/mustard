// @mission: 连通图采用邻接表存储，实现从指定顶点出发的深度优先遍历的非递归过程
#include "11.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();

    char start = 0;
    std::cin >> start;
    dfs(g, start);

    delete g;
    return 0;
}
