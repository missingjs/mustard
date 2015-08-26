#include "70.def.h"

node_t * _bh(const char * & p)
{
    char ch = *p++;
    if (ch == '#') {
        return NULL;
    }
    node_t * n = new node_t(ch);

    ch = *p;
    if (ch == '(') {
        ++p;  // skip ')'
        n->lc = _bh(p);
        ++p;  // skip ','
        n->rc = _bh(p);
        ++p;  // slip ')'
    }

    return n;
}

node_t * build_hierarchical(const char * content)
{
    if (!content || !*content) {
        return NULL;
    }
    const char * p = content;
    node_t * root = _bh(p);
    return root;
}
