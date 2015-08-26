#include "73.def.h"

node_t * _bt(const char * & p);

node_t * _build_forest(const char * & p)
{
    node_t head, *last = &head;
    char ch = 0;
    while (ch != ')') {
        if (ch == ',') {
            ++p;
        }
        node_t * n = _bt(p);
        last->rc = n;
        last = n;
        ch = *p;
    }
    return head.rc;
}

node_t * _bt(const char * & p)
{
    char ch = *p++;
    node_t * n = new node_t(ch);

    ch = *p;
    if (ch == '(') {
        ++p; // skip '('
        node_t * forest = _build_forest(p);
        ++p; // skip ')'
        n->lc = forest;
    }

    return n;
}

node_t * build_tree(const char * content)
{
    const char * p = content;
    return _bt(p);
}
