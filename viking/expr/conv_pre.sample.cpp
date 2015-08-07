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

#include <stack>

struct mt_node
{
    expr_node * * ret;
    int state;

    char op;
    expr_node *e1, *e2;

    mt_node(expr_node ** ret)
        : ret(ret), state(0), op(0), e1(NULL), e2(NULL)
    {}
};

expr_node * make_tree_2(const std::vector<token> & tokens)
{
    cvi_t i = tokens.begin();
    expr_node * root = NULL;

    std::stack<mt_node> stk;
    stk.push(mt_node(&root));

    while (!stk.empty()) {
        mt_node & top = stk.top();
        switch (top.state) {
            case 0:
                if (i->type == token::NUM) {
                    int num = i->d.num;
                    ++i;
                    *top.ret = new expr_node(num);
                    stk.pop();
                } else {
                    top.op = i->d.op;
                    ++i;
                    top.state = 1;
                    stk.push(mt_node(&top.e1));
                }
                break;
            case 1:
                top.state = 2;
                stk.push(mt_node(&top.e2));
                break;
            case 2:
                *top.ret = new expr_node(top.op, top.e1, top.e2);
                stk.pop();
                break;
        }
    }

    return root;
}

void conv_pre(const char * expr, std::string & in, std::string & post)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    // expr_node * root = make_tree_1(tokens);
    expr_node * root = make_tree_2(tokens);

    dump_in(root, in);
    dump_post(root, post);

    delete root;
}
