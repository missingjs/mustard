// @mission: 利用深度优先遍历求关键路径
#include "41.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    show_critical_path(g);
    delete g;
    return 0;
}
