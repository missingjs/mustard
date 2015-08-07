#include <vector>
#include <stack>

#include "_expr_common.cpp"

int _op_prior_table[7][7] = {
    //    +  -  *  /  (  )  #
/* + */ { 1, 1,-1,-1,-1, 1, 1 },
/* - */ { 1, 1,-1,-1,-1, 1, 1 },
/* * */ { 1, 1, 1, 1,-1, 1, 1 },
/* / */ { 1, 1, 1, 1,-1, 1, 1 },
/* ( */ {-1,-1,-1,-1,-1, 0,-2 },
/* ) */ {-2,-2,-2,-2,-2,-2,-2 },
/* # */ {-1,-1,-1,-1,-1,-2, 0 }
};

int _op_index(char c)
{
    switch (c) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '(': return 4;
        case ')': return 5;
        case '#': return 6;
        default : return -1;
    }
}

int op_cmp(char c1, char c2)
{
    int i1 = _op_index(c1);
    int i2 = _op_index(c2);
    if (i1 < 0 || i2 < 0) {
        exit(0);
    }
    return _op_prior_table[i1][i2];
}

int eval_in(const std::vector<token> & _tokens)
{
    token terminal;
    terminal.type = token::OP;
    terminal.d.op = '#';
    std::vector<token> tokens(_tokens);
    tokens.push_back(terminal);

    std::vector<token>::const_iterator i = tokens.begin();
    std::stack<int> num_stk;
    std::stack<char> op_stk;

    op_stk.push('#');

    while (!op_stk.empty()) {
        if (i->type == token::NUM) {
            num_stk.push(i->d.num);
            ++i;
        } else {
            char op = i->d.op;
            int cmp = op_cmp(op_stk.top(), op);
            if (cmp > 0) {
                int n2 = num_stk.top();
                num_stk.pop();
                int n1 = num_stk.top();
                num_stk.pop();
                int value = eval(n1, op_stk.top(), n2);
                num_stk.push(value);
                op_stk.pop();
            } else if (cmp < 0) {
                op_stk.push(op);
                ++i;
            } else {
                op_stk.pop();
                ++i;
            }
        }
    }

    return num_stk.top();
}

int in_eval(const char * expr)
{
    std::vector<token> tokens;
    parse(expr, tokens);
    return eval_in(tokens);
}

