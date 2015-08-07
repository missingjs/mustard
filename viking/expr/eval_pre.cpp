// @mission: 对波兰表达式求值

#include <string>
#include <iostream>

// @param expr 表达式字符串，只包含数字、四则运算符和小括号，不同类符号之间以空格间隔
int pre_eval(const char * expr);

int main()
{
    std::string expr;
    getline(std::cin, expr);

    int value = pre_eval(expr.c_str());
    std::cout << "value: " << value << '\n';

    return 0;
}
