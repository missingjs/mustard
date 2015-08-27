#include "common/graph.h"
#include "common/matrix2.h"
using namespace mustard;

int main()
{
    typedef matrix::symmetric_matrix<int> sm_t;
    typedef graph::undirected_network<char, int, sm_t>  u_net;
    u_net * n1 = graph::read_network<u_net>();
    n1->display(std::cout);
    delete n1;
    return 0;
}
