#include <cstddef>

int str_cmp(const char * s1, const char * s2)
{
    if (!s1 && !s2) {
        return 0;
    } else if (!s1) {
        return -1;
    } else if (!s2) {
        return 1;
    }

    const char *p1 = s1, *p2 = s2;
    while (*p1 && *p2) {
        if (*p1 > *p2) {
            return 1;
        } else if (*p1 < *p2) {
            return -1;
        } else {
            ++p1;
            ++p2;
        }
    }

    if (*p1) {
        return 1;
    } else if (*p2) {
        return -1;
    } else {
        return 0;
    }
}
