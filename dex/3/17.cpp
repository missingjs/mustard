// @mission: 参见17.png

#include <string>
#include <iostream>

bool str_check(const char * str);

int main()
{
    std::string str;
    std::cin >> str;

    bool r = str_check(str.c_str());

    std::cout << (r ? "yes" : "no") << std::endl;

    return 0;
}
