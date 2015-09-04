// @mission: 带权有向无环图G，求G每个顶点出发的最长路径长度，请注意这里求的是最“长”路径，不是最短
#include "36.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    show_each_longest_path(g);
    delete g;
    return 0;
}
