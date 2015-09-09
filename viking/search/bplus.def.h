#include <cstring>

struct bp_node
{
    int n;
    int key[4];
    bp_node * ptr[4];
    bp_node * parent;
    bp_node * next;

    bp_node()
        : n(0), parent(NULL), next(NULL)
    {
        memset(key, 0, sizeof(int) * 4);
        memset(ptr, 0, sizeof(bp_node*) * 4);
    }

    int max_key() const
    {
        return n >= 0 ? key[n-1] : -1;
    }
};

struct bp_tree
{
    bp_node * root;
    bp_node * sqt;
    bp_tree()
        : root(NULL), sqt(NULL)
    {}
};

bp_tree * create_b_plus(int * arr, int n);
void bp_print(bp_tree * tree);
void bp_free(bp_tree * tree);
void remove_from_b_plus(bp_tree * tree, int * arr, int n);
