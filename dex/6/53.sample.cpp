#include "53.def.h"
#include <vector>

void _pp(node_t * root, int & max_lv, 
        std::vector<char> & stk,
        std::vector<char> & path)
{
    if (!root) {
        return;
    }

    stk.push_back(root->data);

    if (stk.size() > max_lv) {
        max_lv = (int) stk.size();
        path = stk;
    }

    _pp(root->lc, max_lv, stk, path);
    _pp(root->rc, max_lv, stk, path);

    stk.pop_back();
}

void left_longest_path(node_t * root, char * output)
{
    int max_level = 0;
    std::vector<char> stk, path;
    _pp(root, max_level, stk, path); // TODO
    for (size_t i = 0; i < path.size(); ++i, ++output) {
        *output = path[i];
    }
    *output = 0;
}
