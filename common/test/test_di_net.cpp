#include "common/graph.h"
using namespace mustard;

int main()
{
    typedef graph::directed_network< char,int,graph::adj_matrix<int> >  mx_net;

    mx_net * n1 = graph::read_network<mx_net>();
    n1->display(std::cout);

    delete n1;
    return 0;
}
