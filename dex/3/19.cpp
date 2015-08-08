// @mission: 判断一个字符串中的括号是否匹配

bool is_match(const char * str);

#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    bool r = is_match(str.c_str());

    std::cout << (r ? "match" : "not match") << '\n';

    return 0;
}
