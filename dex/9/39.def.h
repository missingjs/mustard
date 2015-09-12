#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<int> node_t;

void split(node_t * root, int x, node_t * & t1, node_t * & t2);
