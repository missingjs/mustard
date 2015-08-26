#include "common/bitree.h"
using namespace mustard;

typedef bitree::node<char> node_t;

node_t * build_by_seq_degree(int n, const char * ch, const int * deg);
