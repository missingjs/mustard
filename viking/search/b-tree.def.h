#include <cstring>

struct b_node
{
    int n;
    int key[4];
    b_node *ptr[4];
    b_node *parent;

    b_node()
        : n(0), parent(NULL)
    {
        memset(key, 0, sizeof(int) * 4);
        memset(ptr, 0, sizeof(b_node*) * 4);
    }
};

b_node * create_b_tree(int * arr, int n);
void b_print(b_node * btree);
void b_free(b_node * root);
b_node * remove_element(b_node * root, int * arr, int n);
