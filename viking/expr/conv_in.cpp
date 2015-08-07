// @mission: 将中缀表达式转换为前缀和后缀式

#include <iostream>
#include <string>

// @param expr 表达式字符串，只包含数字、四则运算符和小括号，不同类符号之间以空格间隔
void conv_in(const char * expr, std::string & pre, std::string & post);

int main()
{
    std::string expr;
    getline(std::cin, expr);

    std::string pre, post;
    conv_in(expr.c_str(), pre, post);

    std::cout << "pre: " << pre << '\n';
    std::cout << "post: " << post << '\n';

    return 0;
}
