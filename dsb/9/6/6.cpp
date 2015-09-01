// @mission: 求AOE网的所有关键活动
#include "6.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    print_all_critical_act(g);
    delete g;
    return 0;
}
