#include <cstring>
#include <vector>
#include <cstddef>
#include <iostream>

void show_all_LCS(const char * s, const char * t)
{
    int m = (int) strlen(s);
    int n = (int) strlen(t);

    int max_len = 0;
    std::vector<int> sidx;
    std::vector<int> tidx;

    for (int c = 0; c < n; ++c) {
        int k = 0;
        int i = 0, j = c;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                ++k;
                if (k >= max_len) {
                    if (k > max_len) {
                        max_len = k;
                        sidx.clear();
                        tidx.clear();
                    }
                    sidx.push_back(i);
                    tidx.push_back(j);
                }
            } else {
                k = 0;
            }
            ++i;
            ++j;
        }
    }

    for (int r = 1; r < m; ++r) {
        int i = r, j = 0, k = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                ++k;
                if (k >= max_len) {
                    if (k > max_len) {
                        max_len = k;
                        sidx.clear();
                        tidx.clear();
                    }
                    sidx.push_back(i);
                    tidx.push_back(j);
                }
            } else {
                k = 0;
            }
            ++i;
            ++j;
        }
    }

    std::vector<int> srec((size_t)m, 0);
    std::vector<int> trec((size_t)n, 0);
    
    std::vector<int>::iterator i = sidx.begin(), e = sidx.end();
    for (; i != e; ++i) {
        int start = *i - max_len + 1;
        if (srec[start] == 0) {
            srec[start] = 1;
            std::cout << start << ", ";
            const char * p = s + start;
            for (int off = 0; off < max_len; ++off) {
                std::cout << *(p + off);
            }
            std::cout << '\n';
        }
    }
    std::cout << "--------------------\n";

    i = tidx.begin();
    e = tidx.end();
    for (; i != e; ++i) {
        int start = *i - max_len + 1;
        if (trec[start] == 0) {
            trec[start] = 1;
            std::cout << start << ", ";
            const char * p = t + start;
            for (int off = 0; off < max_len; ++off) {
                std::cout << *(p + off);
            }
            std::cout << '\n';
        }
    }
}
