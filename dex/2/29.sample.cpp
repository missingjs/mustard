#include <stddef.h>

bool forward(const int * b, int Lb, int & bi, const int * c, int Lc, int & ci, int & bc);

void process(int * a, int & La, const int * b, int Lb, const int * c, int Lc)
{
    if (a == NULL || La <= 0) {
        La = 0;
        return;
    } else if (b == NULL || Lb <= 0 || c == NULL || Lc <= 0) {
        return;
    }

    int ai = 0, bi = 0, ci = 0;
    int k = 0;
    int bc = 0;
    bool fw = forward(b,Lb,bi,c,Lc,ci,bc);

    while (ai < La && fw) {
        if (a[ai] < bc) {
            a[k++] = a[ai++];
        } else if (a[ai] > bc) {
            fw = forward(b,Lb,bi,c,Lc,ci,bc);
        } else {
            ++ai;
            fw = forward(b,Lb,bi,c,Lc,ci,bc);
        }
    }

    while (ai < La) {
        a[k++] = a[ai++];
    }

    La = k;
}

bool forward(const int * b, int Lb, int & bi, const int * c, int Lc, int & ci, int & bc)
{
    while (bi < Lb && ci < Lc) {
        if (b[bi] < c[ci]) {
            ++bi;
        } else if (b[bi] > c[ci]) {
            ++ci;
        } else {
            bc = b[bi];
            ++bi;
            ++ci;
            return true;
        }
    }
    return false;
}
