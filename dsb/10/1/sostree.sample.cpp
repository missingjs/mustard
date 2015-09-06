#include <vector>
#include <cstring>
#include <cstdlib>

#include "common/utils.h"
#include "sostree.def.h"

void _acc(double * sw, double * prob, int n)
{
    for (int i = 0; i < n; ++i) {
        sw[i] = sw[i-1] + prob[i];
    }
}

node_t * _bd(int * numbers, double * sw, int low, int high)
{
    if (low > high) {
        return NULL;
    }

    double min = sw[high] - sw[low], dw = sw[high] + sw[low-1];
    std::cout << '[' << (min) << ']' << '\n';
    int i = low;
    for (int j = low + 1; j <= high; ++j) {
        if (min > std::abs((int)(dw - sw[j] - sw[j-1]))) {
            min = std::abs((int)(dw - sw[j] - sw[j-1]));
            i = j;
        }
    }

    node_t * n = new node_t(numbers[i]);
    n->lc = _bd(numbers, sw, low, i - 1);
    n->rc = _bd(numbers, sw, i + 1, high);
    return n;
}

node_t * build_sostree(int * numbers, double * prob, int n)
{
    double * _sw = new double[n+1];
    double * sw = _sw + 1;
    memset(sw, 0, sizeof(double) * (n+1));

    _acc(sw, prob, n);

    node_t * root = _bd(numbers, sw, 0, n - 1);

    delete[] _sw;

    return root;
}

bool search(node_t * root, int k)
{
    if (!root) {
        return false;
    } else if (root->data == k) {
        return true;
    } else if (k < root->data) {
        return search(root->lc, k);
    } else {
        return search(root->rc, k);
    }
}

