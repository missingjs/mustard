// @mission: 表达式由单字母变量和双目四则运算符构成（不含空格），判断给定逆波兰式是否格式正确，若正确，转换为波兰式

#include <string>
#include <iostream>

bool conv_to_polish(const std::string & str, std::string & output);

int main()
{
    std::string rev_polish;
    std::cin >> rev_polish;

    std::string output;
    bool r = conv_to_polish(rev_polish, output);

    if (r) {
        std::cout << output << '\n';
    } else {
        std::cout << "error format\n";
    }

    return 0;
}
