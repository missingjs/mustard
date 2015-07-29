// @brief: 设有一个双链表h，每个结点中除有prev,data,和next 3个域外，还有一个访问频度域freq，在链表被起用之前，每个结点中的freq域值均被初始化为0，每当进行LocateNode(h,x)运算时，令元素值为x的结点中freq域的值加1，并调整表中结点的次序，使其按访问频度的递减序列排列，以便使频繁访问的结点总是靠近表头。编写程序实现LocateNode(h,x)算法

#include <iostream>
#include "common/dlist.h"
#include "common/array.h"
#include "12.h"
using namespace mustard;

typedef dlist::node<cell> node_t;

node_t * locate_node(node_t * h, int data);

std::istream & operator >> (std::istream & in, cell & c)
{
    in >> c.data;
    c.freq = 0;
    return in;
}

std::ostream & operator << (std::ostream & out, const cell & c)
{
    out << '(' << c.data << ',' << c.freq << ')';
    return out;
}

int main()
{
    node_t * f = dlist::read<cell>();

    int len = 0;
    int * visit_list = array::read<int>(len);
    if (!visit_list) {
        len = 0;
    }

    for (int i = 0; i < len; ++i) {
        int d = visit_list[i];
        f = locate_node(f, d);
    }

    dlist::print(f);

    dlist::free(f);
    array::free(visit_list);

    return 0;
}
