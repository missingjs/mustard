// @mission: 将波兰表达式转换为中缀和后缀形式

#include <iostream>
#include <string>

// @param expr 表达式字符串，只包含数字、四则运算符和小括号，不同类符号之间以空格间隔
void conv_pre(const char * expr, std::string & in, std::string & post);

int main()
{
    std::string expr;
    getline(std::cin, expr);

    std::string in, post;
    conv_pre(expr.c_str(), in, post);

    std::cout << "in: " << in << '\n';
    std::cout << "post: " << post << '\n';

    return 0;
}
