#include "32.def.h"
#include <cstring>

void netherland_flag(char * arr, int n)
{
    if (!arr || n <= 0) {
        return;
    }

    char * b = new char[n];
    int na = 0, nb = 0, nc = 0;

    for (int i = 0; i < n; ++i) {
        switch (arr[i]) {
            case 'A':
                b[na*3] = 'A';
                ++na;
                break;
            case 'B':
                b[nb*3+1] = 'B';
                ++nb;
                break;
            case 'C':
                b[nc*3+2] = 'C';
                ++nc;
                break;
        }
    }

    memcpy(arr, b, sizeof(char) * n);
    delete[] b;
}
