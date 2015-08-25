// @mission: 参见58.png
#include "58.def.h"
#include <string>

int main()
{
    node_t * root = bitree::read_threading<char>(bitree::IN_ORDER_THREADING);

    char p = 0;
    std::cin >> p;

    std::string line;
    std::getline(std::cin, line); // skip '\n'

    node_t * x = bitree::read_threading<char>(bitree::IN_ORDER_THREADING);

    node_t * p_node = find_in_order(root, p);

    if (!p_node) {
        std::cout << "no node p\n";
        return 0;
    }

    insert(p_node, x);

    delete x;

    print_threading(root, bitree::IN_ORDER_THREADING);
    print_threading(root, bitree::IN_ORDER_THREADING, true);

    bitree::free_threading(root);

    return 0;
}

