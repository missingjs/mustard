#include <iostream>

#include "rbtree.def.h"

namespace {

    rbnode NIL(0, BLACK);

    rbnode * pNil = &NIL;

    rbnode * new_node(int value = 0, rbcolor color = BLACK)
    {
        rbnode * n = new rbnode(value, color);
        n->parent = n->lc = n->rc = pNil;
        return n;
    }

    rbnode * left_rotate(rbnode * n)
    {
        rbnode * p = n->parent;
        rbnode * r = n->rc;
        n->rc = r->lc;
        r->lc = n;
        r->parent = p;
        n->parent = r;
        if (n == p->lc) {
            p->lc = r;
        } else {
            p->rc = r;
        }
        return r;
    }

    rbnode * right_rotate(rbnode * n)
    {
        rbnode * p = n->parent;
        rbnode * L = n->lc;
        n->lc = L->rc;
        L->rc = n;
        L->parent = p;
        n->parent = L;
        if (n == p->lc) {
            p->lc = L;
        } else {
            p->rc = L;
        }
        return L;
    }

    char get_color(rbcolor color)
    {
        return color == RED ? 'R' : 'B';
    }

    void print_node(rbnode * n)
    {
        std::cout << '(' << n->value << ',' << get_color(n->color) << ") ";
    }

    void preorder_print(rbnode * root)
    {
        if (root != pNil) {
            print_node(root);
            preorder_print(root->lc);
            preorder_print(root->rc);
        }
    }

    void inorder_print(rbnode * root)
    {
        if (root != pNil) {
            inorder_print(root->lc);
            print_node(root);
            inorder_print(root->rc);
        }
    }

    rbnode * _find(rbnode * r, int v)
    {
        if (r == pNil || r->value == v) {
            return r;
        }

        if (v < r->value) {
            return _find(r->lc, v);
        } else {
            return _find(r->rc, v);
        }
    }

    rbnode * get_successor(rbnode * k)
    {
        if (k == pNil || k->rc == pNil) {
            return pNil;
        }

        rbnode * r = k->rc;
        while (r->lc != pNil) {
            r = r->lc;
        }

        return r;
    }

}

RBTree::RBTree()
    : root(pNil)
{
}

void RBTree::insert(int v)
{
    if (root == pNil) {
        root = new_node(v);
        return;
    }

    rbnode * n = find_insert_pos(root, v);
    if (n->value == v) {
        return;
    } else {
        rbnode * c = new_node(v, RED);
        c->parent = n;
        if (v < n->value) {
            n->lc = c;
        } else {
            n->rc = c;
        }
        insert_fixup(c);
    }
}

void RBTree::insert_fixup(rbnode * x)
{
    while (x->parent->color == RED) {
        rbnode * p = x->parent;
        rbnode * g = p->parent;
        if (p == g->lc) {
            rbnode * uncle = g->rc;
            if (uncle->color == RED) {
                p->color = uncle->color = BLACK;
                g->color = RED;
                x = g;
            } else {
                if (x == p->rc) {
                    p = left_rotate(p);
                    x = p->lc;
                }
                g->color = RED;
                p->color = BLACK;
                right_rotate(g);
            }
        } else {
            rbnode * uncle = g->lc;
            if (uncle->color == RED) {
                p->color = uncle->color = BLACK;
                g->color = RED;
                x = g;
            } else {
                if (x == p->lc) {
                    p = right_rotate(p);
                    x = p->rc;
                }
                g->color = RED;
                p->color = BLACK;
                left_rotate(g);
            }
        }
    }
    root->color = BLACK;
}

rbnode * RBTree::find_insert_pos(rbnode * n, int v)
{
    if (n->value == v) {
        return n;
    }

    if (v < n->value) {
        if (n->lc != pNil) {
            return find_insert_pos(n->lc, v);
        } else {
            return n;
        }
    }

    if (v > n->value) {
        if (n->rc != pNil) {
            return find_insert_pos(n->rc, v);
        } else {
            return n;
        }
    }
}

void RBTree::display()
{
    preorder_print(root);
    std::cout << '\n';
    inorder_print(root);
    std::cout << '\n';
}

rbnode * RBTree::find(int v)
{
    return _find(root, v);
}

void RBTree::remove(int v)
{
    rbnode * n = find(v);
    if (n == pNil) {
        return;
    }

    rbnode * y = pNil;
    if (n->lc == pNil || n->rc == pNil) {
        y = n;
    } else {
        y = get_successor(n);
        n->value = y->value;
    }

    rbnode * x = (y->lc == pNil ? y->rc : y->lc);

    x->parent = y->parent;

    rbnode * p = y->parent;
    if (p == pNil) {
        root = x;
    } else if (y == p->lc) {
        p->lc = x;
    } else {
        p->rc = x;
    }

    if (y->color == BLACK) {
        remove_fixup(x);
    }
}

void RBTree::remove_fixup(rbnode * x)
{
    while (x != root && x->color == BLACK) {
        rbnode * p = x->parent;
        if (x == p->lc) { // LEFT CHILD
            rbnode * w = p->rc;
            if (w->color == RED) {
                p->color = RED;
                w->color = BLACK;
                left_rotate(p);
                w = p->rc;
            }

            if (w->lc->color == BLACK && w->rc->color == BLACK) {
                w->color = RED;
                x = p;
            } else {
                if (w->rc->color == BLACK) { // w->rc is red
                    w->color = RED;
                    w->lc->color = BLACK;
                    w = right_rotate(w);
                }

                w->color = p->color;
                p->color = BLACK;
                w->rc->color = BLACK;
                left_rotate(p);

                x = root;
            }
        } else { // right child
            rbnode * w = p->lc;
            if (w->color == RED) {
                p->color = RED;
                w->color = BLACK;
                right_rotate(p);
                w = p->lc;
            }

            if (w->lc->color == BLACK && w->rc->color == BLACK) {
                w->color = RED;
                x = p;
            } else {
                if (w->lc->color == BLACK) { // w->rc is red
                    w->color = RED;
                    w->rc->color = BLACK;
                    w = left_rotate(w);
                }

                w->color = p->color;
                p->color = BLACK;
                w->lc->color = BLACK;
                right_rotate(p);

                x = root;
            }
        }
    }
    x->color = BLACK;
}




