#include <vector>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>

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

struct expr_node
{       
    token::e_type type;                                                    
    int num;                                                               
    char op;
    expr_node * e1;                                                        
    expr_node * e2;                                                        

    expr_node(int num)                                                     
        : type(token::NUM), num(num), op(0), e1(NULL), e2(NULL)            
    {}
    
    expr_node(char op, expr_node * e1 = NULL, expr_node * e2 = NULL)       
        : type(token::OP), num(0), op(op), e1(e1), e2(e2)                  
    {}                                                                     
                                                                           
    ~expr_node() 
    {                                                                      
        delete e1;                                                         
        delete e2;                                                         
    }       
};

void dump_pre(expr_node * root, std::string & output)
{
    if (!root) {
        return;
    }

    if (root->type == token::NUM) {
        char num[20];
        //itoa(root->num, num, 10);
        sprintf(num, "%d", root->num);
        output += num;
        output.push_back(' ');
    } else {
        output.push_back(root->op);
        output.push_back(' ');
        dump_pre(root->e1, output);
        dump_pre(root->e2, output);
    }
}

void dump_in(expr_node * root, std::string & output)
{
    if (!root) {
        return;
    }

    if (root->type == token::NUM) {
        char num[20];
        sprintf(num, "%d", root->num);
        output += num;
        output.push_back(' ');
    } else {
        if (root->e1 && root->e1->type == token::OP) {
            int cmp = op_cmp(root->e1->op, root->op);
            if (cmp < 0) {
                output.push_back('(');
                output.push_back(' ');
            }
            dump_in(root->e1, output);
            if (cmp < 0) {
                output.push_back(')');
                output.push_back(' ');
            }
        } else {
            dump_in(root->e1, output);
        }

        output.push_back(root->op);
        output.push_back(' ');

        if (root->e2 && root->e2->type == token::OP) {
            int cmp = op_cmp(root->op, root->e2->op);
            if (cmp > 0) {
                output.push_back('(');
                output.push_back(' ');
            }
            dump_in(root->e2, output);
            if (cmp > 0) {
                output.push_back(')');
                output.push_back(' ');
            }
        } else {
            dump_in(root->e2, output);
        }
    }
}

void dump_post(expr_node * root, std::string & output)
{
    if (!root) {
        return;
    }

    if (root->type == token::NUM) {
        char num[20];
        sprintf(num, "%d", root->num);
        output += num;
        output.push_back(' ');
    } else {
        dump_post(root->e1, output);
        dump_post(root->e2, output);
        output.push_back(root->op);
        output.push_back(' ');
    }
}
