#include <cstddef>
#include <iostream>

void pp(char * str, char * b, char * e)
{
    if (b == e) {
        for (b = str; b != e; ++b) {
            std::cout << *b << ' ';
        }
        std::cout << '\n';
        return;
    }

    pp(str, b + 1, e);

    for (char * p = b + 1; p != e; ++p) {
        char tmp = *b;
        *b = *p;
        *p = tmp;

        pp(str, b + 1, e);

        tmp = *b;
        *b = *p;
        *p = tmp;
    }
}

void print_permutation(char * str, int len)
{
    if (str == NULL || len <= 0) {
        return;
    }

    pp(str, str, str + len);
}
