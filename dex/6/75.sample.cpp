#include "75.def.h"
#include <vector>
#include <iostream>

int _bt(const char * & p, std::vector<tree_cell> & nodes);

child_node * _forest(const char * & p, std::vector<tree_cell> & nodes)
{
    if (*p != '(') {
        return NULL;
    }

    ++p;  // skip '('

    char ch = 0;
    child_node head, *last = &head;
    while (ch != ')') {
        int id = _bt(p, nodes);
        child_node * c = new child_node(id);
        last->link = c;
        last = c;
        ch = *p++;
    }

    return head.link;
}

int _bt(const char * & p, std::vector<tree_cell> & nodes)
{
    char ch = *p++;
    nodes.push_back(tree_cell(ch));
    int id = (int) (nodes.size() - 1);

    child_node * ch_forest = _forest(p, nodes);
    nodes[id].child = ch_forest;

    return id;
}

void _dump(tree_t * tree)
{
    for (int i = 0; i < tree->num_nodes; ++i) {
        std::cout << i << ' ' << tree->nodes[i].data << " -> ";
        child_node * pc = tree->nodes[i].child;
        while (pc) {
            std::cout << pc->id << ' ';
            pc = pc->link;
        }
        std::cout << '\n';
    }
}

tree_t * build_tree(const char * content)
{
    if (!content || !*content) {
        return NULL;
    }
    std::vector<tree_cell> nodes;
    const char * p = content;
    _bt(content, nodes);

    tree_t * tree = new tree_t((int) nodes.size());
    for (size_t i = 0; i < nodes.size(); ++i) {
        tree->nodes[i] = nodes[i];
        nodes[i].child = NULL;
    }

    // _dump(tree);

    return tree;
}

void _pt(tree_t * tree, int id)
{
    std::cout << tree->nodes[id].data;
    if (tree->nodes[id].child) {
        std::cout << '(';
        child_node * c = tree->nodes[id].child;
        while (c) {
            _pt(tree, c->id);
            c = c->link;
            if (c) {
                std::cout << ',';
            }
        }
        std::cout << ')';
    }
}

void print_tree(tree_t * tree)
{
    _pt(tree, 0);
    std::cout << '\n';
}

void free_tree(tree_t * tree)
{
    for (int i = 0; i < tree->num_nodes; ++i) {
        child_node * pc = tree->nodes[i].child;
        while (pc) {
            child_node * d = pc;
            pc = pc->link;
            delete d;
        }
    }

    delete tree;
}
