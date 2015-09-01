// @mission: 设v是有向图G的一个顶点，把v的偏心度定义为：MAX{从w到v的最知距离|w属于V(G)}。若v是有向图G中具有的最小偏心度的顶点，则称顶点v是G的中心点。
#include "9.def.h"

int main()
{
    graph_t * g = graph::read_network<graph_t>();
    char c = get_center_point(g);
    std::cout << "center point: " << c << '\n';
    delete g;
    return 0;
}
