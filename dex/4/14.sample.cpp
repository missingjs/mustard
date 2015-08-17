#include <cstddef>
#include <cctype>

struct node
{
    enum type_enum { OP, NUM };

    type_enum type;
    char data;
    node * left;
    node * right;

    node(type_enum type, char d)
        : type(type), data(d), left(NULL), right(NULL)
    {}

    ~node() { delete left; delete right; }
};

node * create_tree(const char * & pre_input)
{
    if (isalpha(*pre_input)) {
        return new node(node::NUM, *pre_input++);
    }

    node * root = new node(node::OP, *pre_input++);
    node * left = create_tree(pre_input);
    node * right = create_tree(pre_input);
    root->left = left;
    root->right = right;
    return root;
}

void dump_post(node * root, char * & out)
{
    if (root->type == node::NUM) {
        *out = root->data;
        ++out;
    } else {
        dump_post(root->left, out);
        dump_post(root->right, out);
        *out = root->data;
        ++out;
    }
}

void pre_to_post(const char * pre, char * post)
{
    const char * p = pre;
    node * root = create_tree(p);
    
    char * out = post;
    dump_post(root, out);

    delete root;
}
