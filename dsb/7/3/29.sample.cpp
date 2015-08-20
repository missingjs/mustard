#include "common/bitree.h"
#include <vector>
using namespace mustard;

typedef bitree::node<char> node_t;

void _show_path(const std::vector<node_t*> & path)
{
    typedef typename std::vector<node_t*>::const_reverse_iterator it_t;
    it_t i = path.rbegin(), e = path.rend();
    for (; i != e; ++i) {
        std::cout << (*i)->data << ' ';
    }
    std::cout << '\n';
}

void _p_1(node_t * root, std::vector<node_t*> & path)
{
    if (!root) {
        return;
    }

    path.push_back(root);
    if (!root->lc && !root->rc) {
        _show_path(path);
    }

    _p_1(root->lc, path);
    _p_1(root->rc, path);

    path.pop_back();
}

void print_1(node_t * root)
{
    std::vector<node_t*> path;
    _p_1(root, path);
}

struct cell
{
    node_t * node;
    int parent;
    cell(node_t * n, int p)
        : node(n), parent(p)
    {}
};

void print_2(node_t * root)
{
    if (!root) {
        return;
    }
    std::vector<cell> arr;
    arr.push_back(cell(root, -1));
    for (int i = 0; i < (int) arr.size(); ++i) {
        cell c = arr[i];
        if (!c.node->lc && !c.node->rc) {
            int j = i;
            while (j >= 0) {
                std::cout << arr[j].node->data << ' ';
                j = arr[j].parent;
            }
            std::cout << '\n';
        }
        if (c.node->lc) {
            arr.push_back(cell(c.node->lc, i));
        }
        if (c.node->rc) {
            arr.push_back(cell(c.node->rc, i));
        }
    }
}

void print_all_path(node_t * root)
{
    print_1(root);
    std::cout << "---------------------\n";
    print_2(root);
}
