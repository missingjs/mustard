// @brief: 一个不带表头的单链表，实现以下算法：
// [1] 求结点个数
// [2] 顺序打印链表元素 
// [3] 逆序打印链表元素
// [4] 删除值为x的第一个结点
// [5] 删除值为x的所有结点
// [6] 求最大值
// [7] 求最小值

#include "common/slist.h"
using namespace mustard;

typedef slist::node<int> node_t;

int count_nodes(node_t * h);
void print_forward(node_t * h);
void print_backward(node_t * h);
node_t * remove_first_x(node_t * h, int x);
node_t * remove_all_x(node_t * h, int x);
bool get_max(node_t * h, int & max);
bool get_min(node_t * h, int & min);

int main()
{
    node_t * h = slist::read<int>();
    int x = 0;
    std::cin >> x;

    std::cout << "size: " << count_nodes(h) << std::endl;
    
    print_forward(h);

    print_backward(h);

    node_t * h1 = slist::clone(h);
    h1 = remove_first_x(h1, x);
    std::cout << "remove first " << x << ": ";
    slist::print(h1);
    slist::free(h1);

    node_t * h2 = slist::clone(h);
    h2 = remove_all_x(h2, x);
    std::cout << "remove all " << x << ": ";
    slist::print(h2);
    slist::free(h2);

    int max = 0;
    if (get_max(h, max)) {
        std::cout << "max: " << max << std::endl;
    } else {
        std::cout << "no max found" << std::endl;
    }

    int min = 0;
    if (get_min(h, min)) {
        std::cout << "min: " << min << std::endl;
    } else {
        std::cout << "no min found" << std::endl;
    }

    slist::free(h);

    return 0;
}
