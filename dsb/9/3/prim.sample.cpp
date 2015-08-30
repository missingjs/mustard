#include "prim.def.h"

struct _prm
{
    int v;   // belong to chosen collection
    int u;   // un-chosen
    int weight;
};

int _find_min(_prm * vect, int size)
{
    int m = 0;
    for (int i = 1; i < size; ++i) {
        if (vect[i].weight < vect[m].weight) {
            m = i;
        }
    }
    return m;
}

void prim_print_edge(graph_t * g)
{
    if (!g) {
        return;
    }

    int C = g->vex_count();
    if (C <= 1) {
        return;
    }

    mx_t & mx = *(g->get_structure());

    int size = C - 1;
    _prm * vect = new _prm[size];

    for (int i = 0; i < size; ++i) {
        int j = i + 1;
        vect[i].v = 0;
        vect[i].u = j;
        vect[i].weight = mx[0][j];
    }

    int unlimit = graph::numeric_weight<int>::unconnected_value();
    while (size > 0) {
        int m = _find_min(vect, size);
        if (vect[m].weight == unlimit) {
            std::cout << "no a connected graph!\n";
            break;
        }
        std::cout << '[' << g->vex(vect[m].u) << "] " 
            << g->vex(vect[m].v) << ' ' << vect[m].weight << '\n';

        if (m != size - 1) {
            _prm tmp = vect[m];
            vect[m] = vect[size-1];
            vect[size-1] = tmp;
        }
        int u = vect[size-1].u;
        for (int i = 0; i < size-1; ++i) {
            int w = mx[u][vect[i].u];
            if (w < vect[i].weight) {
                vect[i].weight = w;
                vect[i].v = u;
            }
        }
        --size;
    }

    delete[] vect;
}
