#include <iostream>
#include <vector>
#include <stddef.h>

#include "common/matrix2.h"
#include "euler.def.h"

struct node
{
    int adj;
    node * next;
    node(int adj = -1) : adj(adj), next(0) {}
};

struct node_list
{
    node * head;
    node * tail;
    int len;
    node_list() : head(NULL), tail(NULL), len(0) {}

    void clear()
    {
        head = tail = NULL;
        len = 0;
    }
};

typedef typename list_t::node arc_t;
typedef matrix::common_matrix<int> mx_t;

int count_edge(list_t * L)
{
    int c = 0;
    for (int i = 0; i < L->size(); ++i) {
        for (arc_t * p = L->_heads[i]; p; p = p->next) {
            ++c;
        }
    }
    return c / 2;
}

bool _dfs(std::vector<arc_t*> & last, int root, int s, mx_t & mx, node_list & NL)
{
    for (arc_t * p = last[s]; p; p = p->next) {
        int adj = p->adj;
        last[s] = p->next;
        if (mx[s][adj] == 1) {
            continue;
        }
        mx[s][adj] = mx[adj][s] = 1;
        if (adj == root) {
            node * n = new node(root);
            NL.head = NL.tail = n;
            ++NL.len;
            return true;
        } else {
            if (!_dfs(last, root, adj, mx, NL)) {
                return false;
            }
            node * n = new node(adj);
            ++NL.len;
            n->next = NL.head;
            NL.head = n;
            return true;
        }
    }

    return false;
}

void find_euler_circuit(graph_t * g)
{
    int N = g->vex_count();
    list_t * L = g->get_structure();
    int num_edges = count_edge(L);

    node *head = NULL, *p = NULL;
    node_list NL;

    mx_t mx(N, N, 0);

    std::vector<arc_t*> last(N);
    for (int i = 0; i < N; ++i) {
        last[i] = L->_heads[i];
    }

    int C = 0;
    head = p = new node(0);
    while (C < num_edges && p) {
        NL.clear();
        if (!_dfs(last, p->adj, p->adj, mx, NL)) {
            if (NL.len > 0) {
                std::cout << "ERROR GRAPH\n";
                return;
            } else {
                p = p->next;
                continue;
            }
        } else {
            NL.tail->next = p->next;
            p->next = NL.head;
            C += NL.len;
        }
    }

    if (C < num_edges) {
        std::cout << "NOT visited edges\n";
        return;
    }

    std::cout << "Euler Circuit: ";
    for (node * q = head; q; q = q->next) {
        std::cout << g->vex(q->adj) << ' ';
    }
    std::cout << std::endl;
}
