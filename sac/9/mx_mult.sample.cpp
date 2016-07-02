#include <limits>
#include <iostream>
#include <vector>
#include "mx_mult.def.h"

struct node
{
    int v;
    int c;
    node *lc, *rc;

    node(int v = 0) : v(v), c(0), lc(NULL), rc(NULL) {}
};

static int counter = 0;

node * mk_tree(const mx_t & M, const mx_t & P, int a, int b)
{
    if (a == b) {
        return new node(-a);
    }

    int i = P[a][b];
    node * lc = mk_tree(M, P, a, i);
    node * rc = mk_tree(M, P, i + 1, b);
    node * root = new node(++counter);
    root->c = M[a][b];
    root->lc = lc;
    root->rc = rc;
    return root;
}

void display(node * root, const char * m, const mx_t & M)
{
    if (root->v < 0) {
        return;
    }

    display(root->lc, m, M);
    display(root->rc, m, M);

    if (root->lc->v < 0) {
        std::cout << m[-root->lc->v-1] << " * ";
    } else {
        std::cout << root->lc->v << " * ";
    }

    if (root->rc->v < 0) {
        std::cout << m[-root->rc->v-1];
    } else {
        std::cout << root->rc->v;
    }
    std::cout << " -> " << root->v << " [" << root->c << ']' << '\n';
}

void optimal_matrix_multiply(int N, const char * m, const int * rows, const int * cols)
{
    mx_t M(N+1, N+1), P(N+1, N+1);
    std::vector<int> C(N + 1);

    C[0] = rows[0];
    for (int i = 0; i < N; ++i) {
        C[i+1] = cols[i];
    }

    for (int k = 1; k < N; ++k) {
        for (int i = 1; i <= N-k; ++i) {
            int begin = i;
            int end = i + k;
            M[begin][end] = std::numeric_limits<int>::max();
            for (int j = begin; j < end; ++j) {
                int a1 = M[begin][j];
                int a3 = M[j+1][end];
                int a2 = C[begin-1] * C[j] * C[end];
                int T = a1 + a2 + a3;
                if (T < M[begin][end]) {
                    M[begin][end] = T;
                    P[begin][end] = j;
                }
            }
        }
    }

    std::cout << "min value: " << M[1][N] << '\n';

    node * root = mk_tree(M, P, 1, N);
    display(root, m, M);
}
