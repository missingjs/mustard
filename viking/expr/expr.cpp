// @mission: 实现波兰、中缀、逆波兰表达式的相互转化和求值

#include <string>
#include <iostream>

// @param type 表达式类型，PRE / IN / POST
// @param expr 表达式字符串，只包含数字、四则运算符和小括号，不同类符号之间以空格间隔
// 求值，并打印对应的三类表达式
void expr_process(const char * type, const char * expr);

int main()
{
    std::string type, expr;

    std::cin >> type;
    getline(std::cin, expr); // skip \n
    getline(std::cin, expr);

    expr_process(type.c_str(), expr.c_str());

    return 0;
}
