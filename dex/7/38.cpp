// @mission: 一个四则运算表达式以有向无环图的邻接表方式存储，每个操作数都由单个字母表示，输出其逆波兰表达式，并按照提供的操作数的值，求表达式的值
#include "38.def.h"

// @desc: 输入数据由“图”、“符号映射”、“左右操作数关系”和“操作数值”四部分组成

int main()
{
    graph_t * g = graph::read_graph<graph_t>();
    int C = g->vex_count();

    char symbols[128];
    load_symbols(symbols, C);

    mx_t mx(C, C);
    load_operand_relation(mx);

    int values[128];
    load_operand_values(values, C);

    std::cout << "rev polish: ";
    print_reverse_polish(g, mx, symbols);

    int v = evaluate(g, mx, symbols, values);
    std::cout << "value: " << v << '\n';

    delete g;
    return 0;
}
