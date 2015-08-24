#include <cstring>
#include <iostream>

void _ps(const char * b, const char * e, char * buf, int i)
{
    if (b == e) {
        if (i == 0) {
            std::cout << "[]\n";
        } else {
            buf[i] = 0;
            std::cout << buf << '\n';
        }
        return;
    }

    buf[i] = *b;
    _ps(b + 1, e, buf, i + 1);

    _ps(b + 1, e, buf, i);
}

void print_powerset(const char * str)
{
    if (!str || !*str) {
        std::cout << "[]\n";
        return;
    }

    size_t len = strlen(str);
    char * buf = new char[len+1];
    _ps(str, str + len, buf, 0);
    delete[] buf;
}
