#include <stack>
#include <list>
#include "common/matrix.h"
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

struct mz
{
    int r, c;
    int dir;

    mz(int r, int c)
        : r(r), c(c), dir(0)
    {}
};

bool is_in(matrix_t * m, int r, int c)
{
    return r >= 0 && r < m->row && c >= 0 && c < m->col;
}

void dump_path(std::stack<mz> & stk, std::list<mz> & path)
{
    path.clear();

    while (!stk.empty()) {
        path.push_front(stk.top());
        stk.pop();
    }

    for (std::list<mz>::iterator i = path.begin(); i != path.end(); ++i) {
        stk.push(*i);
    }
}

void print_path(const std::list<mz> & path)
{
    std::cout << "path => " << path.size() << '\n';
    int c = 0;
    for (std::list<mz>::const_iterator i = path.begin(); i != path.end(); ++i) {
        std::cout << '(' << i->r << ',' << i->c << ") ";
        ++c;
        if (c % 5 == 0) {
            std::cout << '\n';
        }
    }

    std::cout << '\n';
    if (c % 5) {
        std::cout << '\n';
    }
}

void print_path(std::stack<mz> & stk)
{
    std::list<mz> path;
    dump_path(stk, path);
    print_path(path);
}

void print_path(matrix_t * m, int br, int bc, int er, int ec)
{
    if (m == NULL || !is_in(m,br,bc) || !is_in(m,er,ec) 
            || m->get(br, bc) != 0 || m->get(er,ec) != 0) 
    {
        return;
    }

    std::stack<mz> stk;
    std::list<mz> path;

    m->set(br,bc,-1);
    stk.push(mz(br,bc));

    while (!stk.empty()) {
        mz & top = stk.top();
        if (top.r == er && top.c == ec) {
            if (path.size() == 0 || stk.size() < path.size()) {
                dump_path(stk, path);
                print_path(path);
            } else {
                print_path(stk);
            }
            m->set(top.r, top.c, 0);
            stk.pop();
            continue;
        }
        if (top.dir > 3) {
            m->set(top.r, top.c, 0);
            stk.pop();
            continue;
        }
        int n_r = 0, n_c = 0;
        switch (top.dir) {
            case 0:
                n_r = top.r - 1;
                n_c = top.c;
                break;
            case 1:
                n_r = top.r;
                n_c = top.c + 1;
                break;
            case 2:
                n_r = top.r + 1;
                n_c = top.c;
                break;
            case 3:
                n_r = top.r;
                n_c = top.c - 1;
                break;
        }
        ++top.dir;
        if (m->get(n_r,n_c) == 0) {
            m->set(n_r,n_c,-1);
            stk.push(mz(n_r,n_c));
        }
    }

    std::cout << "the shortest path: \n";
    print_path(path);
}
