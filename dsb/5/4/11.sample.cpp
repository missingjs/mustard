#include <cstring>
#include <cstddef>
#include <iostream>

int do_cmp(const char * p1, const char * p2)
{
    int len = 0;
    while (*p1 && *p2 && *p1++ == *p2++) {
        ++ len;
    }
    return len;
}

char * f1(const char * s1, const char * s2)
{
    int max_len = 0, index = -1;
    for (int i = 0; s1[i]; ++i) {
        for (int j = 0; s2[j]; ++j) {
            int len = do_cmp(s1 + i, s2 + j);
            if (len > max_len) {
                index = i;
                max_len = len;
            }
        }
    }

    char * t = new char[max_len+1];
    strncpy(t, s1 + index, max_len);
    t[max_len] = 0;
    return t;
}

char * f2(const char * s1, const char * s2)
{
    int m = (int) strlen(s1);
    int n = (int) strlen(s2);
    int * a = new int[m * n];

    int max_len = 0;
    int mi = 0, mj = 0;

    for (int i = 0; i < n; ++i) {
        a[i] = (s1[0] == s2[i]) ? 1 : 0;
        if (max_len == 0 && a[i] == 1) {
            max_len = 1;
            mi = 0;
            mj = i;
        }
    }
    for (int i = 1; i < m; ++i) {
        a[i * n] = (s1[i] == s2[0]) ? 1 : 0;
        if (max_len == 0 && a[i*n] == 1) {
            max_len = 1;
            mi = i;
            mj = 0;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            int & target = a[i * n + j];
            if (s1[i] == s2[j]) {
                target = a[(i-1)*n + j - 1] + 1;
                if (target > max_len) {
                    max_len = target;
                    mi = i;
                    mj = j;
                }
            } else {
                target = 0;
            }
        }
    }

    delete[] a;

    char * t = new char[max_len+1];
    t[max_len] = 0;
    strncpy(t, s1 + mi - max_len + 1, max_len);
    return t;
}

char * f3(const char * s1, const char * s2)
{
    int m = (int) strlen(s1);
    int n = (int) strlen(s2);

    int * a = new int[n];

    int max_len = 0, last_index = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = (s1[0] == s2[i]) ? 1 : 0;
        if (max_len == 0 && a[i] > 0) {
            max_len = a[i];
            last_index = i;
        }
    }

    for (int r = 1; r < m; ++r) {
        for (int c = n - 1; c > 0; --c) {
            a[c] = (s1[r] == s2[c]) ? (a[c-1] + 1) : 0;
            if (a[c] > max_len) {
                max_len = a[c];
                last_index = c;
            }
        }
        a[0] = (s1[r] == s2[0]) ? 1 : 0;
        if (max_len == 0 && a[0] == 1) {
            max_len = 1;
            last_index = 0;
        }
    }

    delete[] a;

    char * t = new char[max_len + 1];
    t[max_len] = 0;
    strncpy(t, s2 + last_index - max_len + 1, max_len);
    return t;
}

char * f4(const char * s1, const char * s2)
{
    int m = (int) strlen(s1);
    int n = (int) strlen(s2);
    int max_len = 0, last_index = -1;

    for (int c = 0; c < n; ++c) {
        int i = 0, j = c;
        int len = (s1[i] == s2[j]) ? 1 : 0;
        if (max_len == 0 && len == 1) {
            max_len = 1;
            last_index = j;
        }
        ++i; ++j;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                ++len;
                if (max_len < len) {
                    max_len = len;
                    last_index = j;
                }
            } else {
                len = 0;
            }
            ++i; ++j;
        }
    }

    for (int r = 1; r < m; ++r) {
        int i = r, j = 0;
        int len = (s1[i] == s2[j]) ? 1 : 0;
        if (max_len == 0 && len == 1) {
            max_len = 1;
            last_index = j;
        }
        ++i; ++j;
        while (i < m && j < n) {
            if (s1[i] == s2[j]) {
                ++len;
                if (max_len < len) {
                    max_len = len;
                    last_index = j;
                }
            } else {
                len = 0;
            }
            ++i; ++j;
        }
    }

    char * t = new char[max_len + 1];
    t[max_len] = 0;
    strncpy(t, s2 + last_index - max_len + 1, max_len);
    return t;
}

char * longest_common_substring(const char * s1, const char * s2)
{
    return f4(s1, s2);
}
