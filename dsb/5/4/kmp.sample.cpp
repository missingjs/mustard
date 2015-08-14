#include <cstddef>
#include <cstring>
#include <iostream>

void get_next(const char * pat, int len, int * next)
{
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len) {
        if (j == -1 || pat[i] == pat[j]) {
            ++i;
            ++j;
            if (pat[i] == pat[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }
}

int find_sub(const char * str, const char * sub)
{
    if (!str || !sub) {
        return -1;
    }

    int len = (int) strlen(sub);
    int * next = new int[len + 1];

    get_next(sub, len, next);

    int i = 0, j = 0;
    while (str[i] && j < len) {
        if (j == -1 || str[i] == sub[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }

    delete[] next;

    return !sub[j] ? i - j : -1;
}

void print_all_index(const char * str, const char * sub)
{
    if (!str || !sub) {
        return;
    }

    int sub_len = (int) strlen(sub);
    int * next = new int[sub_len + 1];

    get_next(sub, sub_len, next);

    int i = 0, j = 0;
    while (str[i]) {
        while (str[i] && j < sub_len) {
            if (j == -1 || str[i] == sub[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j == sub_len) {
            std::cout << (i-j) << ' ';
            j = next[j];
        }
    }
    std::cout << '\n';

    delete[] next;
}
