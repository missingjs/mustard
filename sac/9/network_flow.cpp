// @mission: network flow algorithm
//           打印最大流，以及包含的各个边

#include "network_flow.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    int begin, end;
    std::cin >> begin >> end;
    network_flow_process(g, begin, end);
    delete g;
    return 0;
}
