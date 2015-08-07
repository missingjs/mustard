#include <string>
#include "_expr_common.cpp"

expr_node * make_tree_in(const std::vector<token> & _tokens)
{
    std::vector<token> tokens(_tokens);
    token term;
    term.type = token::OP;
    term.d.op = '#';
    tokens.push_back(term);
    std::vector<token>::iterator i = tokens.begin();

    std::stack<expr_node*> num_stk;
    std::stack<char> op_stk;
    op_stk.push('#');

    while (!op_stk.empty()) {
        if (i->type == token::NUM) {
            num_stk.push(new expr_node(i->d.num));
            ++i;
        } else {
            char top = op_stk.top();
            char cur = i->d.op;
            int cmp = op_cmp(top, cur);
            if (cmp > 0) {
                op_stk.pop();
                expr_node * e2 = num_stk.top();
                num_stk.pop();
                expr_node * e1 = num_stk.top();
                num_stk.pop();
                expr_node * e = new expr_node(top, e1, e2);
                num_stk.push(e);
            } else if (cmp == 0) {
                op_stk.pop();
                ++i;
            } else {
                op_stk.push(cur);
                ++i;
            }
        }
    }

    return num_stk.top();
}

void conv_in(const char * expr, std::string & pre, std::string & post)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    expr_node * root = make_tree_in(tokens);

    dump_pre(root, pre);
    dump_post(root, post);

    delete root;
}
