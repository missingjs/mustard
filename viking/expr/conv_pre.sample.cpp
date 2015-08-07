#include <string>
#include <vector>

#include "_expr_common.cpp"

typedef std::vector<token>::iterator vi_t;
typedef std::vector<token>::const_iterator cvi_t;

expr_node * mt1(cvi_t & i)
{
    if (i->type == token::NUM) {
        int num = i->d.num;
        ++i;
        return new expr_node(num);
    } else {
        char op = i->d.op;
        ++i;
        expr_node * e1 = mt1(i);
        expr_node * e2 = mt1(i);
        return new expr_node(op, e1, e2);
    }
}

expr_node * make_tree_1(const std::vector<token> & tokens)
{
    cvi_t i = tokens.begin();
    return mt1(i);
}

void conv_pre(const char * expr, std::string & in, std::string & post)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    expr_node * root = make_tree_1(tokens);

    dump_in(root, in);
    dump_post(root, post);

    delete root;
}
