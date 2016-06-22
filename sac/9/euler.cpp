// @mission: Find euler circuit
#include "euler.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    find_euler_circuit(g);
    delete g;
    return 0;
}
