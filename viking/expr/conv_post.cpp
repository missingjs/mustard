// @mission: 将后缀（逆波兰）表达式转换为前缀和中缀式

#include <iostream>
#include <string>

// @param expr 表达式字符串，只包含数字、四则运算符和小括号，不同类符号之间以空格间隔
void conv_post(const char * expr, std::string & pre, std::string & in);

int main()
{
    std::string expr;
    getline(std::cin, expr);

    std::string pre, in;
    conv_post(expr.c_str(), pre, in);

    std::cout << "pre: " << pre << '\n';
    std::cout << "in: " << in << '\n';

    return 0;
}
