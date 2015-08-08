#include <string>
#include <stack>
#include <cctype>

struct e_node
{
    char token;
    e_node * lc;
    e_node * rc;

    e_node(char t, e_node * lc = NULL, e_node * rc = NULL)
        : token(t), lc(lc), rc(rc)
    {}

    ~e_node()
    {
        delete lc;
        delete rc;
    }
};

void dump_polish(e_node * root, std::string & output)
{
    if (!root) {
        return;
    }

    output.push_back(root->token);
    if (root->lc) {
        dump_polish(root->lc, output);
    }
    if (root->rc) {
        dump_polish(root->rc, output);
    }
}

bool conv_1(const std::string & str, std::string & output)
{
    std::stack<e_node*> stk;
    const char * p = str.c_str();

    while (*p) {
        if (isalpha(*p)) {
            stk.push(new e_node(*p));
        } else if (stk.size() >= 2) {
            e_node * e2 = stk.top();
            stk.pop();
            e_node * e1 = stk.top();
            stk.pop();
            e_node * e = new e_node(*p,e1,e2);
            stk.push(e);
        } else {
            break;
        }
        ++p;
    }

    if (stk.size() != 1 || *p) {
        while (!stk.empty()) {
            delete stk.top();
            stk.pop();
        }
        return false;
    }

    e_node * root = stk.top();

    dump_polish(root, output);

    delete root;

    return true;
}

bool conv_to_polish(const std::string & str, std::string & output)
{
    return conv_1(str, output);
}
