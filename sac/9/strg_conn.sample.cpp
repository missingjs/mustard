#include <vector>
#include "strg_conn.def.h"


typedef typename list_t::node arc_t;

struct adjlist
{
    arc_t ** heads;
    int size;
    adjlist(int size) : size(size), heads(new arc_t*[size]) 
    {
        for (int i = 0; i < size; ++i) {
            heads[i] = NULL;
        }
    }
};

std::vector<int> visited;
//std::vector<int> num;
std::vector<int> vex;
int counter = 0;

void prepare(list_t * L, int s, adjlist & rL)
{
    visited[s] = 1;
    for (arc_t * p = L->_heads[s]; p; p = p->next) {
        int a = p->adj;
        arc_t * ac = new arc_t;
        ac->adj = s;
        ac->next = rL.heads[a];
        rL.heads[a] = ac;
        if (!visited[a]) {
            prepare(L, a, rL);
        }
    }
    vex[counter] = s;
    ++counter;
}

void _dfs(graph_t * g, adjlist & rL, int s)
{
    std::cout << g->vex(s) << ' ';
    visited[s] = 1;
    for (arc_t * p = rL.heads[s]; p; p = p->next) {
        if (!visited[p->adj]) {
            _dfs(g, rL, p->adj);
        }
    }
}

void print_strongly_connected_components(graph_t * g)
{
    int N = g->vex_count();
    visited.assign(N, 0);
//    num.assign(N, -1);
    vex.assign(N, -1);
    list_t * L = g->get_structure();

    adjlist rL(N);
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            prepare(L, i, rL);
        }
    }

//    for (int i = 0; i < N; ++i) {
//        std::cout << g->vex(i) << " -> ";
//        for (arc_t * p = rL.heads[i]; p; p = p->next) {
//            std::cout << g->vex(p->adj) << ' ';
//        }
//        std::cout << '\n';
//    }

    visited.assign(N, 0);
    for (auto i = vex.rbegin(); i != vex.rend(); ++i) {
        if (visited[*i]) {
            continue;
        }
        std::cout << "strongly connected components: ";
        _dfs(g, rL, *i);
        std::cout << std::endl;
    }
}
