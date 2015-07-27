// @brief: 单链表表示集合，求两个集合交集

#include <algorithm>
#include "common/slist.h"
#include "common/array.h"
using namespace mustard;

// unorder -> 无序
// ro -> read only, 不改变原有链表

// 无序， 只读
slist::node<int> * intersect_unorder_ro(slist::node<int> * s1, slist::node<int> * s2);

// 无序，利用s1空间
slist::node<int> * intersect_unorder(slist::node<int> * s1, slist::node<int> * s2);

// 有序，只读
slist::node<int> * intersect_order_ro(slist::node<int> * s1, slist::node<int> * s2);

// 有序，利用s1空间
slist::node<int> * intersect_order(slist::node<int> * s1, slist::node<int> * s2);

int main()
{
    int a1_len = 0;
    int * a1 = array::n_read<int>(a1_len);

    int a2_len = 0;
    int * a2 = array::n_read<int>(a2_len);

    slist::node<int> * s1 = slist::from_array(a1, a1_len);
    slist::node<int> * s2 = slist::from_array(a2, a2_len);
    slist::node<int> * s_u_ro = intersect_unorder_ro(s1, s2);
    slist::print(s_u_ro);
    slist::free(s_u_ro);

    slist::node<int> * s_u = intersect_unorder(s1, s2);
    slist::print(s_u);
    slist::free(s_u);
    slist::free(s2);

    std::sort(a1, a1 + a1_len);
    std::sort(a2, a2 + a2_len);

    s1 = slist::from_array(a1, a1_len);
    s2 = slist::from_array(a2, a2_len);
    slist::node<int> * s_ro = intersect_order_ro(s1, s2);
    slist::print(s_ro);
    slist::free(s_ro);

    slist::node<int> * s = intersect_order(s1, s2);
    slist::print(s);
    slist::free(s);
    slist::free(s2);

    array::free(a1);
    array::free(a2);

    return 0;
}
