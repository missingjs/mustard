// @mission: 求二叉数最左最长路径（根到叶）
#include "53.def.h"

int main()
{
    node_t * root = bitree::read<char>();
    char * path = new char[1024];
    left_longest_path(root, path);
    std::cout << path << '\n';
    delete[] path;
    bitree::free(root);
    return 0;
}
