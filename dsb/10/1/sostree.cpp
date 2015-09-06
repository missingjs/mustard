// @mission: 提供一组有序数字，和相应的查找概率，构造次优查找数，并完成查找过程
#include "sostree.def.h"

int main()
{
    int len = 0;
    int * numbers = array::read<int>(len);
    double * prob = array::read<double>(len);
    int k = 0;
    std::cin >> k;

    node_t * root = build_sostree(numbers, prob, len);

    bitree::print(root, bitree::HIERARCHY_FORMAT);

    bool r = search(root, k);

    std::cout << std::boolalpha << r << '\n';

    bitree::free(root);
    delete[] numbers;
    delete[] prob;
    return 0;
}
