#include "38.def.h"
#include <vector>

int _find_entry(list_t * L, int C)
{
    std::vector<int> indeg(C, 0);
    for (int i = 0; i < C; ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            ++indeg[p->adj];
        }
    }

    for (int i = 0; i < C; ++i) {
        if (indeg[i] == 0) {
            return i;
        }
    }

    return -1;
}

void _dfs(graph_t * g, list_t * L, int v, 
        const mx_t & mx, const char * symbols)
{
    arc_t * p = L->_heads[v];
    if (p) {
        int n1 = p->adj, n2 = p->next->adj;
        int left, right;
        if (mx[n1][n2] > 0) {
            left = n1;
            right = n2;
        } else {
            left = n2;
            right = n1;
        }
        _dfs(g, L, left, mx, symbols);
        _dfs(g, L, right, mx, symbols);
    }
    std::cout << symbols[v];
}

void print_reverse_polish(graph_t * g, 
        const mx_t & mx, const char * symbols)
{
    if (!g) {
        return;
    }

    int C = g->vex_count();
    list_t * L = g->get_structure();

    int start = _find_entry(L, C);
    if (start < 0) {
        std::cout << "not a DAG!\n";
        return;
    }

    _dfs(g, L, start, mx, symbols);
    std::cout << '\n';
}

void load_operand_relation(mx_t & mx)
{
    int n;
    std::cin >> n;
    int left, right;
    for (int i = 0; i < n; ++i) {
        std::cin >> left >> right;
        mx[left][right] = 1;
        mx[right][left] = -1;
    }
}

void load_operand_values(int * values, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
}

void load_symbols(char * symbols, int n)
{
    for (int i = 0; i < n; ++i) {
        std::cin >> symbols[i];
    }
}

int _cal(char op, int n1, int n2)
{
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return 0;
    }
}

int _dfs_v(graph_t * g, list_t * L, int v, 
        const mx_t & mx, const char * symbols, 
        const int * values)
{
    arc_t * p = L->_heads[v];
    if (!p) {
        return values[v];
    } else {
        int n1 = p->adj, n2 = p->next->adj;
        int left, right;
        if (mx[n1][n2] > 0) {
            left = n1;
            right = n2;
        } else {
            left = n2;
            right = n1;
        }
        n1 = _dfs_v(g,L,left,mx,symbols,values);
        n2 = _dfs_v(g,L,right,mx,symbols,values);
        return _cal(symbols[v], n1, n2);
    }
}

int evaluate(graph_t * g, const mx_t & mx, 
        const char * symbols, const int * values)
{
    int C = g->vex_count();
    list_t * L = g->get_structure();

    int start = _find_entry(L, C);

    return _dfs_v(g, L, start, mx, symbols, values);
}
