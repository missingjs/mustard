#ifndef SAC_3_BASE_H
#define SAC_3_BASE_H 1

struct exp_node
{
    int c, e;

    exp_node(int c = 0, int e = 0):
        c(c), e(e)
    {}
};

struct exp_link_node : public exp_node
{
    exp_link_node * next;

    exp_link_node(int c = 0, int e = 0):
        exp_node(c,e), next(NULL)
    {}
};

exp_link_node * read_exp_list();
void free_exp_list(exp_link_node * h);
void print_exp_list(exp_link_node * h);

#endif
