#include <vector>
#include <stack>

#include "_expr_common.cpp"

struct pre_node
{
    char op;
    int n1, n2;
    bool k1, k2;

    pre_node(char op)
        : op(op), n1(0), n2(0), k1(false), k2(false)
    {}
};

int eval_pre(const std::vector<token> & tokens)
{
    std::stack<pre_node> stk;
    std::vector<token>::const_iterator i = tokens.begin();
    if (i->type == token::NUM) {
        return i->d.num;
    }

    stk.push(pre_node(i->d.op));

    int result = 0;

    while (!stk.empty()) {
        pre_node & top = stk.top();
        if (!top.k1) {
            ++i;
            if (i->type == token::NUM) {
                top.n1 = i->d.num;
                top.k1 = true;
            } else {
                stk.push(pre_node(i->d.op));
            }
        } else if (!top.k2) {
            ++i;
            if (i->type == token::NUM) {
                top.n2 = i->d.num;
                top.k2 = true;
            } else {
                stk.push(pre_node(i->d.op));
            }
        } else {
            int v = eval(top.n1, top.op, top.n2);
            stk.pop();
            if (!stk.empty()) {
                pre_node & t = stk.top();
                if (!t.k1) {
                    t.n1 = v;
                    t.k1 = true;
                } else if (!t.k2) {
                    t.n2 = v;
                    t.k2 = true;
                }
            } else {
                result = v;
            }
        }
    }
    
    return result;
}

namespace {

typedef std::vector<token>::const_iterator cvi_t;

int _e(cvi_t & i)
{
    if (i->type == token::NUM) {
        int num = i->d.num;
        ++i;
        return num;
    } else {
        char op = i->d.op;
        ++i;
        int n1 = _e(i);
        int n2 = _e(i);
        return eval(n1, op, n2);
    }
}

int r_eval(const std::vector<token> & tokens)
{
    cvi_t i = tokens.begin();
    return _e(i);
}

struct _ne
{
    int * ret;
    int state;
    char op;
    int n1, n2;
    _ne(int * ret)
        : ret(ret), state(0), op(0), n1(0), n2(0)
    {}
};

int nr_eval(const std::vector<token> & tokens)
{
    cvi_t i = tokens.begin();
    int value = 0;
    std::stack<_ne> stk;
    stk.push(_ne(&value));

    while (!stk.empty()) {
        _ne & top = stk.top();
        switch (top.state) {
            case 0:
                if (i->type == token::NUM) {
                    *top.ret = i->d.num;
                    stk.pop();
                    ++i;
                } else {
                    top.op = i->d.op;
                    ++i;
                    top.state = 1;
                    stk.push(_ne(&top.n1));
                }
                break;
            case 1:
                top.state = 2;
                stk.push(_ne(&top.n2));
                break;
            case 2:
                *top.ret = eval(top.n1, top.op, top.n2);
                stk.pop();
                break;
        }
    }

    return value;
}

}

int pre_eval(const char * expr)
{
    std::vector<token> tokens;
    parse(expr, tokens);
    // return eval_pre(tokens);
    // return r_eval(tokens);
    return nr_eval(tokens);
}
