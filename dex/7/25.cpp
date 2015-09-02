// @mission: 参见25.png
#include "25.def.h"

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    std::vector<int> s, fst, lst;
    build(g, s, fst, lst);
    bool r = has_loop(s, fst, lst);
    delete g;
    const char *yes = "yes", *no = "no";
    std::cout << (r ? "yes" : "no") << '\n';
    return 0;
}
