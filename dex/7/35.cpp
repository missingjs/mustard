// @mission: 若在DAG图中存在一个顶点r，在r和图中所有其他顶点之间均存在由r出发的有向路径，则称该DAG图有根。编写算法实现求根过程
#include "35.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    find_root(g);
    delete g;
    return 0;
}
