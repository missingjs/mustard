// @mission: 表达式由单字母变量、双目四则运算符和括号构成，将中缀表达式（格式正确）转换为逆波兰式

#include <string>
#include <iostream>

std::string to_rev_polish(const std::string & expr);

int main()
{
    std::string expr;
    getline(std::cin, expr);

    std::string rev_polish = to_rev_polish(expr);

    std::cout << rev_polish << '\n';

    return 0;
}
