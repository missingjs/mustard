#include <vector>
#include <stack>

#include "_expr_common.cpp"

int eval_post(const std::vector<token> & tokens)
{
    std::vector<token>::const_iterator i = tokens.begin();

    std::stack<int> num_stk;
    for (; i != tokens.end(); ++i) {
        if (i->type == token::NUM) {
            num_stk.push(i->d.num);
        } else {
            int n2 = num_stk.top();
            num_stk.pop();
            int n1 = num_stk.top();
            num_stk.pop();
            int value = eval(n1, i->d.op, n2);
            num_stk.push(value);
        }
    }

    return num_stk.top();
}

int post_eval(const char * expr)
{
    std::vector<token> tokens;
    parse(expr, tokens);
    return eval_post(tokens);
}

