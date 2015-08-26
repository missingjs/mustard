#include <cstddef>

struct child_node
{
    int id;
    child_node * link;
    child_node(int id = -1)
        : id(id), link(NULL)
    {}
};

struct tree_cell
{
    char data;
    child_node * child;
    tree_cell(char d = 0)
        : data(d), child(NULL)
    {}
};

struct tree_t
{
    tree_cell * nodes;
    int num_nodes;
    tree_t(int n)
        : nodes(new tree_cell[n]), num_nodes(n)
    {}

    ~tree_t()
    {
        delete[] nodes;
    }
};

tree_t * build_tree(const char * content);

void print_tree(tree_t * tree);

void free_tree(tree_t * tree);

