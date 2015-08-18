#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <vector>
#include <iostream>

int _cmp(const void * p1, const void * p2)
{
    return strcmp(*(char**)p1, *(char**)p2);
}

int prefix_len(const char * p1, const char * p2)
{
    int len = 0;
    while (*p1 && *p2 && *p1++ == *p2++) {
        ++len;
    }
    return len;
}

void print_all_LRS(const char * str)
{
    int len = (int) strlen(str);

    const char ** suffix = new const char* [len];

    for (int i = 0; i < len; ++i) {
        suffix[i] = &str[i];
    }

    qsort(suffix, len, sizeof(const char*), _cmp);

    int max_len = 0;
    std::vector<int> idxes;
    for (int i = 1; i < len; ++i) {
        int L = prefix_len(suffix[i-1], suffix[i]);
        if (L >= max_len) {
            if (L > max_len) {
                idxes.clear();
                max_len = L;
            }
            idxes.push_back((int)(suffix[i] - str));
            idxes.push_back((int)(suffix[i-1] - str));
        }
    }

    std::vector<int> rec((size_t)len, 0);
    std::vector<int>::iterator i = idxes.begin(), e = idxes.end();
    for (; i != e; ++i) {
        if (rec[*i] == 0) {
            const char * p = str + *i;
            std::cout << *i << ", ";
            for (int k = 0; k < max_len; ++k) {
                std::cout << *(p+k);
            }
            std::cout << '\n';
            rec[*i] = 1;
        }
    }
}
