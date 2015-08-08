#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iostream>

namespace {

char next_char(const char * & p)
{
    while (*p && *p == ' ') {
        ++p;
    }
    return *p;
}

bool is_var(char ch)
{
    return isalpha(ch);
}

char _op[] = "+-*/()#";

const int NUM_OP = sizeof(_op)/sizeof(char) - 1;

int op_table[NUM_OP][NUM_OP] = {
          /*  +  -  *  /  (  )  #  */
    /* + */ { 1, 1,-1,-1,-1, 1, 1 },
    /* - */ { 1, 1,-1,-1,-1, 1, 1 },
    /* * */ { 1, 1, 1, 1,-1, 1, 1 },
    /* / */ { 1, 1, 1, 1,-1, 1, 1 },
    /* ( */ {-1,-1,-1,-1,-1, 0,-2 },
    /* ) */ {-2,-2,-2,-2,-2,-2,-2 },
    /* # */ {-1,-1,-1,-1,-1,-2, 0 }
};

int op_index[128];

struct _init_t
{
    _init_t()
    {
        op_index['+'] = 0;
        op_index['-'] = 1;
        op_index['*'] = 2;
        op_index['/'] = 3;
        op_index['('] = 4;
        op_index[')'] = 5;
        op_index['#'] = 6;
    }
};

_init_t _init;

int op_cmp(char c1, char c2)
{
    int i1 = op_index[c1], i2 = op_index[c2];
    if (i1 < 0 || i1 > NUM_OP || i2 < 0 || i2 > NUM_OP) {
        std::cout << "invalid operator: " << c1 << ',' << c2 << '\n';
        exit(-1);
    }

    int c = op_table[i1][i2];
    if (c < -1) {
        std::cout << "expression format error\n";
        exit(-2);
    }

    return c;
}

}  // anonymous namespace

std::string to_rev_polish(const std::string & expr)
{
    std::string _expr = expr;
    _expr.push_back('#');

    std::string rev_polish;
    std::stack<char> op_stk;

    op_stk.push('#');
    const char * p = _expr.c_str();
    next_char(p);

    while (!op_stk.empty()) {
        if (is_var(*p)) {
            rev_polish.push_back(*p);
            next_char(++p);
        } else {
            char top = op_stk.top();
            int cmp = op_cmp(top, *p);
            if (cmp < 0) {
                op_stk.push(*p);
                next_char(++p);
            } else if (cmp > 0) {
                rev_polish.push_back(top);
                op_stk.pop();
            } else {
                op_stk.pop();
                next_char(++p);
            }
        }
    }

    return rev_polish;
}

