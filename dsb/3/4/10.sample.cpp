#include <cstddef>
#include <iostream>

void pc(const char * b, const char * e, int m, char * output, char * p)
{
    int n = e - b;

    if (n < m) {
        return;
    } else if (m == 0) {
        for (char * i = output; i != p; ++i) {
            std::cout << *i << ' ';
        }
        std::cout << '\n';
        return;
    }

    *p = *b;
    pc(b + 1, e, m - 1, output, p + 1);

    pc(b + 1, e, m, output, p);
}

void print_combination(const char * str, int n, int m)
{
    if (!str || n <= 0 || m <= 0 ||  m > n) {
        return;
    }

    char * output = new char[n];
    pc(str, str + n, m, output, output);
    delete[] output;
}
