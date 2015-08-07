#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>

struct token
{
    enum e_type { NUM, OP };
    enum e_type type;
    union {
        int num;
        char op;
    } d;
};

bool read_token(const char * & p, token & tk)
{
    while (*p && *p == ' ') {
        ++p;
    }

    if (!*p) {
        return false;
    }

    const char * s = p;
    while (*p && *p != ' ') {
        ++p;
    }

    if (!isdigit(*s)) {
        tk.type = token::OP;
        tk.d.op = *s;
    } else {
        char num[20], *t = num;
        while (s != p) {
            *t++ = *s++;
        }
        *t = 0;
        
        tk.type = token::NUM;
        tk.d.num = atoi(num);
    }

    return true;
}

void parse(const char * expr, std::vector<token> &tokens)
{
    const char * p = expr;
    token tk;
    while (read_token(p, tk)) {
        tokens.push_back(tk);
    }
}

struct pre_node
{
    char op;
    int n1, n2;
    bool k1, k2;

    pre_node(char op)
        : op(op), n1(0), n2(0), k1(false), k2(false)
    {}
};

int eval(int n1, char op, int n2)
{
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return 0;
    }
}

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

void expr_process(const char * type, const char * expr)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    int value = 0;
    if (strcmp(type, "PRE") == 0) {
        value = eval_pre(tokens);
    } else if (strcmp(type, "IN") == 0) {
        //value = eval_in(tokens);
    } else if (strcmp(type, "POST") == 0) {
        //value = eval_post(tokens);
    } else {
        std::cout << "unknown type: " << type << '\n';
        return;
    }

    std::cout << "value: " << value << '\n';
}
































