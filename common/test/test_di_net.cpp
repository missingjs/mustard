#include "common/graph.h"
#include "common/matrix2.h"
using namespace mustard;

int main()
{
    typedef matrix::common_matrix<int> matrix_t;
    typedef graph::directed_network<char, int, matrix_t>  mx_net;

    mx_net * n1 = graph::read_network<mx_net>();
    n1->display(std::cout);

    delete n1;
    return 0;
}
