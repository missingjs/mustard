#include <cstddef>
#include <cstring>

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

int find_last_index(const char * str, const char * substr)
{
    int index = -1;

    int sub_len = (int) strlen(substr);
    int * next = new int[sub_len + 1];
    get_next(substr, sub_len, next);

    int i = 0, j = 0;
    while (str[i]) {
        while (str[i] && j < sub_len) {
            if (j == -1 || str[i] == substr[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j == sub_len) {
            index = i - j;
            j = next[j];
        }
    }

    delete[] next;

    return index;
}
