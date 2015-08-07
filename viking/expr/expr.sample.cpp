#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>

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

void expr_process(const char * type, const char * expr)
{
    std::vector<token> tokens;
    parse(expr, tokens);

    for (std::vector<token>::iterator i = tokens.begin();
            i != tokens.end(); ++i)
    {
        if (i->type == token::NUM) {
            std::cout << "num, " << i->d.num;
        } else {
            std::cout << "op, " << i->d.op;
        }
        std::cout << '\n';
    }
}
































