#include <stack>
#include <cstring>
#include "common/matrix.h"
#include "common/slist.h"
using namespace mustard;

struct path_node
{
    int r, c;
    slist::node<path_node> * pre;

    path_node(int r = 0, int c = 0)
        : r(r), c(c), pre(NULL)
    {}
};

typedef mtx::matrix<int> matrix_t;
typedef slist::node<path_node> node_t;

bool is_in(matrix_t * m, int r, int c)
{
    return r >= 0 && r < m->row && c >= 0 && c < m->col;
}

void show_path(matrix_t * m, int br, int bc, int er, int ec)
{
    node_t head, *front = new node_t(path_node(br,bc)), *tail = front;
    head.next = front;

    int * level = new int[m->row * m->col];
    memset(level, 0, sizeof(int) * m->row * m->col);
    level[br + m->col + bc] = 1;

    for (; front; front = front->next) {
        if (front->data.r == er && front->data.c == ec) {
            continue;
        }
        int n_r = 0, n_c = 0;
        for (int i = 0; i <= 3; ++i) {
            switch (i) {
                case 0:
                    n_r = front->data.r - 1;
                    n_c = front->data.c;
                    break;
                case 1:
                    n_r = front->data.r;
                    n_c = front->data.c + 1;
                    break;
                case 2:
                    n_r = front->data.r + 1;
                    n_c = front->data.c;
                    break;
                case 3:
                    n_r = front->data.r;
                    n_c = front->data.c - 1;
                    break;
            }
            node_t * pre = front->data.pre;
            if (is_in(m,n_r,n_c) && m->get(n_r,n_c) == 0) {
                if (!pre) {
                    node_t * n = new node_t(path_node(n_r,n_c));
                    n->data.pre = front;
                    tail->next = n;
                    tail = n;
                } else if (n_r != pre->data.r || n_c != pre->data.c) {
                    int next_level = level[n_r * m->col + n_c];
                    int cur_level = level[front->data.r * m->col + front->data.c] + 1;
                    if (next_level == 0 || cur_level <= next_level) {
                        node_t * n = new node_t(path_node(n_r,n_c));
                        n->data.pre = front;
                        tail->next = n;
                        tail = n;
                        if (next_level == 0) {
                            level[n_r * m->col + n_c] = cur_level;
                        }
                    }
                }
            }
        }
    }

    std::stack<path_node> stk;
    for (node_t * p = head.next; p; p = p->next) {
        if (p->data.r == er && p->data.c == ec) {
            std::stack<path_node> stk;
            for (node_t * t = p; t; t = t->data.pre) {
                stk.push(path_node(t->data.r, t->data.c));
            }
            std::cout << "path => " << stk.size() << '\n';
            int cc = 0;
            while (!stk.empty()) {
                path_node & top = stk.top();
                std::cout << '(' << top.r << ',' << top.c << ") ";
                stk.pop();
                ++cc;
                if (cc % 5 == 0) {
                    std::cout << '\n';
                }
            }
            std::cout << '\n';
            if (cc % 5) {
                std::cout << '\n';
            }
        }
    }

    delete[] level;
}
