#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<int> node_t;

node_t * create_bst(int * arr, int n);
node_t * remove(node_t * root, int * del, int n);
