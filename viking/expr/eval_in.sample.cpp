#include <vector>
#include <stack>

#include "_expr_common.cpp"

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

