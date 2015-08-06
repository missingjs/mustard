#include "common/matrix.h"
#include <vector>
#include <stack>
using namespace mustard;

typedef mtx::matrix<int> matrix_t;

struct step
{
    int r, c;
};

std::vector<step> path_steps;

bool is_in(matrix_t * m, int r, int c)
{
    return r >= 0 && r < m->row && c >= 0 && c < m->col;
}

template <typename Iter>
void print_path(Iter begin, Iter end)
{
    int i = 0;
    std::cout << "path => " << (end - begin) << '\n';
    for (Iter p = begin; p != end; ++p) {
        std::cout << '(' << p->r << ',' << p->c << ") ";
        ++i;
        if (i % 5 == 0) {
            std::cout << '\n';
        }
    }
    std::cout << '\n';
    if (i % 5) {
        std::cout << '\n';
    }
}

void sp(matrix_t * m, int br, int bc, int er, int ec, step * steps, step * p)
{
    if (br == er && bc == ec) {
        p->r = br;
        p->c = bc;
        ++p;
        int len = p - steps;
        if (path_steps.size() == 0 || len < path_steps.size()) {
            path_steps.clear();
            for (step * i = steps; i != p; ++i) {
                path_steps.push_back(*i);
            }
        }
        print_path(steps, p);
        return;
    }

    m->set(br, bc, -1);
    p->r = br;
    p->c = bc;

    int rr = 0, cc = 0;

    for (int dir = 0; dir < 4; ++dir) {
        switch (dir) {
            case 0: rr = br - 1; cc = bc; break;
            case 1: rr = br; cc = bc + 1; break;
            case 2: rr = br + 1; cc = bc; break;
            case 3: rr = br; cc = bc - 1; break;
        }
        if (is_in(m,rr,cc) && m->get(rr,cc) == 0) {
            sp(m, rr, cc, er, ec, steps, p + 1);
        }
    }

    m->set(br, bc, 0);
}

void show_path(matrix_t * m, int br, int bc, int er, int ec)
{
    if (!m || !is_in(m, br, bc) || !is_in(m, er, ec)) {
        return;
    }

    step * steps = new step[m->row * m->col];
    sp(m, br, bc, er, ec, steps, steps);

    std::cout << "shortest path: \n";
    print_path(path_steps.begin(), path_steps.end());

    delete[] steps;
}

struct spn
{
    matrix_t * m;
    int br, bc, er, ec;
    step * steps, *p;
    int state;

    int dir;

    spn(matrix_t * m, int br, int bc, int er, int ec, step * steps, step * p)
        : m(m), br(br), bc(bc), er(er), ec(ec), steps(steps), p(p), state(0)
    {}
};

void show_path_2(matrix_t * m, int br, int bc, int er, int ec)
{
    if (!m) {
        return;
    }

    path_steps.clear();

    step * steps = new step[m->row * m->col];

    std::stack<spn> stk;
    stk.push(spn(m,br,bc,er,ec,steps,steps));

    while (!stk.empty()) {
        spn & top = stk.top();
        if (top.state == 0) {
            if (top.br == top.er && top.bc == top.ec) {
                top.p->r = top.br;
                top.p->c = top.bc;
                ++top.p;
                int len = top.p - top.steps;
                if (path_steps.size() == 0 || len < path_steps.size()) {
                    path_steps.clear();
                    for (step * i = top.steps; i != top.p; ++i) {
                        path_steps.push_back(*i);
                    }
                }
                print_path(top.steps, top.p);
                stk.pop();
            } else {
                top.m->set(top.br, top.bc, -1);
                top.p->r = top.br;
                top.p->c = top.bc;
                top.dir = 0;
                int rr = 0, cc = 0;
                for (; top.dir < 4; ++top.dir) {
                    switch (top.dir) {
                        case 0: rr = top.br - 1; cc = top.bc; break;
                        case 1: rr = top.br; cc = top.bc + 1; break;
                        case 2: rr = top.br + 1; cc = top.bc; break;
                        case 3: rr = top.br; cc = top.bc - 1; break;
                    }
                    if (is_in(top.m,rr,cc) && top.m->get(rr,cc) == 0) {
                        top.state = 1;
                        stk.push(spn(top.m,rr,cc,top.er,top.ec,top.steps, top.p + 1));
                        break;
                    }
                }

                if (top.dir < 4) {
                    continue;
                }
                top.m->set(top.br, top.bc, 0);
                stk.pop();
            }
        } else { // state == 1
            ++top.dir;
            while (top.dir < 4) {
                int rr = 0, cc = 0;
                switch (top.dir) {
                    case 0: rr = top.br - 1; cc = top.bc; break;       
                    case 1: rr = top.br; cc = top.bc + 1; break;       
                    case 2: rr = top.br + 1; cc = top.bc; break;       
                    case 3: rr = top.br; cc = top.bc - 1; break;
                }
                if (is_in(top.m,rr,cc) && top.m->get(rr,cc) == 0) {
                    top.state = 1;
                    stk.push(spn(top.m,rr,cc,top.er,top.ec,top.steps,top.p+1));
                    break;
                }
                ++top.dir;
            }

            if (top.dir < 4) {
                continue;
            }

            top.m->set(top.br, top.bc, 0);
            stk.pop();
        }
    }

    delete[] steps;

    std::cout << "shortest path: \n";
    print_path(path_steps.begin(), path_steps.end());
}


























