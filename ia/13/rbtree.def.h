#include <cstddef>

enum rbcolor
{
    BLACK, RED
};

struct rbnode
{
    int value;
    rbcolor color;

    rbnode *parent, *lc, *rc;

    rbnode(int value = 0, rbcolor color = BLACK) :
        value(value), color(color), parent(NULL),
        lc(NULL), rc(NULL)
    {}
};

class RBTree
{
public:
    RBTree();

    void display();

    void insert(int v);

    void remove(int v);

private:
    rbnode * find_insert_pos(rbnode * n, int v);

    void insert_fixup(rbnode * x);

    rbnode * find(int v);

    void remove_fixup(rbnode * x);

private:
    rbnode * root;
};

