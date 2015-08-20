#include "common/bitree.h"
#include <queue>
using namespace mustard;

typedef bitree::node<char> node_t;

struct N
{
    node_t * node;
    int level;
    N(node_t * n, int L)
        : node(n), level(L)
    {}
};

int get_width(node_t * root)
{
    if (!root) {
        return 0;
    }

    std::queue<N> qu;
    qu.push(N(root, 1));

    int count = 0;
    int cur_level = 1;
    int max_c = 0;
    while (!qu.empty()) {
        N & f = qu.front();
        if (f.level == cur_level) {
            ++count;
        } else {
            count = 1;
            cur_level = f.level;
        }
        if (count > max_c) {
            max_c = count;
        }
        if (f.node->lc) {
            qu.push(N(f.node->lc, f.level + 1));
        }
        if (f.node->rc) {
            qu.push(N(f.node->rc, f.level + 1));
        }
        qu.pop();
    }
    return max_c;
}
