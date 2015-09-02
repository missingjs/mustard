// @mission: 对无环有向图的顶点重新编号，使其邻接矩阵变为下三角形，并输出新旧编号对照表
#include "26.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    convert(g);
    delete g;
    return 0;
}
