#include "common/bitree.h"
using namespace mustard;

typedef bitree::threading_node<char> node_t;

node_t * find_in_order(node_t * root, char p);

void insert(node_t * p, node_t * x);
