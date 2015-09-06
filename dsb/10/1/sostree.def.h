#include "common/array.h"
#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<int> node_t;

node_t * build_sostree(int * numbers, double * prob, int n);
bool search(node_t * root, int k);
