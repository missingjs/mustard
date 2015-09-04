#include "common/graph.h"
using namespace mustard;

typedef graph::adj_list<bool> list_t;
typedef typename list_t::node arc_t;
typedef graph::directed_graph<char,list_t> graph_t;
typedef matrix::common_matrix<int> mx_t;

void print_reverse_polish(graph_t * g, const mx_t & mx, const char * symbols);
void load_symbols(char * symbols, int n);
void load_operand_relation(mx_t & mx);
void load_operand_values(int * values, int n);
int evaluate(graph_t * g, const mx_t & mx, const char * symbols, const int * values);
