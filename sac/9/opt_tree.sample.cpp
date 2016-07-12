#include <iostream>
#include <limits>
#include <vector>

#include "opt_tree.def.h"

typedef matrix::common_matrix<int> rootmx_t;

struct node
{
    int w;
    node *lc, *rc;

    node(int w = -1) :
        w(w), lc(NULL), rc(NULL)
        {}
};

node * mk_tree(const rootmx_t & roots, int left, int right)
{
    if (left == right) {
        return new node(left);
    } else if (left > right) {
        return NULL;
    }

    int r = roots[left][right];
    node * lc = mk_tree(roots, left, r - 1);
    node * rc = mk_tree(roots, r + 1, right);
    node * root = new node(r);
    root->lc = lc;
    root->rc = rc;
    return root;
}

void pre_trav(node * root, const std::vector<std::string> & words)
{
    if (root) {
        std::cout << words[root->w] << ' ';
        pre_trav(root->lc, words);
        pre_trav(root->rc, words);
    }
}

void in_trav(node * root, const std::vector<std::string> & words)
{
    if (root) {
        in_trav(root->lc, words);
        std::cout << words[root->w] << ' ';
        in_trav(root->rc, words);
    }
}

void destroy(node * root)
{
    if (root) {
        destroy(root->lc);
        destroy(root->rc);
        delete root;
    }
}

void optimal_search_tree(int N, const std::vector<std::string> & words, const std::vector<double> & p)
{
    rootmx_t roots(N,N);
    mx_t cost(N,N), pn(N,N);
    double MAX = std::numeric_limits<double>::max();

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cost[i][j] = MAX;
            pn[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        cost[i][i] = pn[i][i] = p[i];
        roots[i][i] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            cost[i][j] = pn[i][j] = 0;
        }
    }

    for (int k = 1; k < N; ++k) {
        for (int left = 0; left < N - k; ++left) {
            int right = left + k;
            pn[left][right] = pn[left][right-1] + p[right];
            for (int i = left; i <= right; ++i) {
                double c = pn[left][right] + cost[left][i-1] + cost[i+1][right];
                if (c < cost[left][right]) {
                    cost[left][right] = c;
                    roots[left][right] = i;
                }
            }
        }
    }

    std::cout << "min cost: " << cost[0][N-1] << '\n';

    node * opt_tree = mk_tree(roots, 0, N-1);

    pre_trav(opt_tree, words);
    std::cout << '\n';
    in_trav(opt_tree, words);
    std::cout << '\n';
    destroy(opt_tree);
}
