#include <string>
#include "_expr_common.cpp"

expr_node * make_tree_post(const std::vector<token> & tokens)
{
    std::stack<expr_node*> stk;
    std::vector<token>::const_iterator i = tokens.begin();
    for (; i != tokens.end(); ++i) {
        if (i->type == token::NUM) {
            stk.push(new expr_node(i->d.num));
        } else {
            expr_node * e2 = stk.top();
            stk.pop();
            expr_node * e1 = stk.top();
            stk.pop();
            expr_node * e = new expr_node(i->d.op, e1, e2);
            stk.push(e);
        }
    }
    return stk.top();
}

void conv_post(const char * expr, std::string & pre, std::string & in)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    expr_node * root = make_tree_post(tokens);

    dump_pre(root, pre);
    dump_in(root, in);

    delete root;
}
