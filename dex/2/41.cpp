// @brief: 以循环链表作稀疏多项式的存储结构（系数和指数约定同39题），编写求其导函数的算法，要求利用原多项式中的结点空间存放导函数（多项式），同时释放所有无用结点
#include "def.h"
#include "common/slist.h"
using namespace mustard;

typedef dex_2::poly_term<int,int> term_t;
typedef slist::node<term_t> node_t;

node_t * to_derivative(node_t * tail);

int main()
{
    node_t * h = slist::read<term_t>();
    node_t * tail = slist::make_circular(h);

    tail = to_derivative(tail);

    h = de_circular(tail);

    slist::print(h);
    slist::free(h);

    return 0;
}
