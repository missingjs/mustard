#include "common/bitree.h"
#include <vector>
using namespace mustard;

typedef bitree::node<char> node_t;

void _collect(
        node_t * root, std::vector<node_t*> & path,
        char a, std::vector<node_t*> & apath,
        char b, std::vector<node_t*> & bpath)
{
    if (!root || apath.size() > 0 && bpath.size() > 0) {
        return;
    }

    path.push_back(root);

    if (root->data == a) {
        apath = path;
    }
    if (root->data == b) {
        bpath = path;
    }

    _collect(root->lc, path, a, apath, b, bpath);
    _collect(root->rc, path, a, apath, b, bpath);

    path.pop_back();
}

node_t * minimal_common_ancestor(node_t * root, char a, char b)
{
    if (!root) {
        return NULL;
    }

    std::vector<node_t*> path, apath, bpath;
    _collect(root, path, a, apath, b, bpath);
    if (apath.size() == 0 || bpath.size() == 0) {
        return NULL;
    }

    int i = 0;
    for (; i < (int)apath.size() && i < (int)bpath.size() 
            && apath[i]->data == bpath[i]->data; ++i)
    {}

    return apath[i-1];
}

struct nps
{
    char ch;
    bitree::node<nps> * parent;
    nps()
        : ch(0), parent(NULL)
    {}
};

typedef bitree::node<nps> n2_t;

n2_t * convert(node_t * root)
{
    if (!root) {
        return NULL;
    }

    n2_t * nr = new n2_t;
    nr->data.ch = root->data;

    n2_t * lc = convert(root->lc);
    if (lc) {
        lc->data.parent = nr;
        nr->lc = lc;
    }
    n2_t * rc = convert(root->rc);
    if (rc) {
        rc->data.parent = nr;
        nr->rc = rc;
    }

    return nr;
}

void _collect(n2_t * root, char a, n2_t * & pa, char b, n2_t * & pb)
{
    if (!root || pa && pb) {
        return;
    }

    if (root->data.ch == a) {
        pa = root;
    }
    if (root->data.ch == b) {
        pb = root;
    }

    _collect(root->lc, a, pa, b, pb);
    _collect(root->rc, a, pa, b, pb);
}

n2_t * minimal_common_ancestor(n2_t * root, char a, char b)
{
    n2_t *pa = NULL, *pb = NULL;
    _collect(root, a, pa, b, pb);
    if (!pa || !pb) {
        return NULL;
    }

    n2_t *i = pa, *j = pb;
    int ca = 0, cb = 0;
    for (; i && j; i = i->data.parent, j = j->data.parent, ++ca, ++cb)
        ;;
    for (; i; i = i->data.parent, ++ca)
        ;;
    for (; j; j = j->data.parent, ++cb)
        ;;

    int diff = 0;
    if (ca >= cb) {
        i = pa;
        j = pb;
        diff = ca - cb;
    } else {
        j = pa;
        i = pb;
        diff = cb - ca;
    }

    for (int k = 0; k < diff; ++k, i = i->data.parent)
        ;;

    for (; i != j; i = i->data.parent, j = j->data.parent)
        ;;

    return i;
}

