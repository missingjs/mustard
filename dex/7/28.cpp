// @mission: 参见28.png
#include "28.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    find_all_path(g);
    delete g;
    return 0;
}
