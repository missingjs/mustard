enum link_type
{
    NODE_LINK,
    THREAD_LINK
};

template <typename T>
struct _threading
{
    T data;
    link_type ltype, rtype;
    _threading(
            const T & t = T(), 
            link_type lt = NODE_LINK,
            link_type rt = NODE_LINK)
        : data(t), ltype(lt), rtype(rt)
    {}

    bool operator==(const _threading<T> & t) const
    {
        return this->data == t.data;
    }
    bool operator!=(const _threading<T> & t) const
    {
        return operator==(t);
    }
};

template <typename T>
std::istream & operator>>(std::istream & in, _threading<T> & t)
{
    return (in >> t.data);
}

template <typename T>
using threading_node = node< _threading<T> >;

template <>
threading_node<char> * read_hierarchy< char, threading_node<char> >();

enum threading_type
{
    PRE_ORDER_THREADING,
    IN_ORDER_THREADING,
    POST_ORDER_THREADING
};

template <typename T>
void _connect_threading_link(threading_node<T> * node, threading_node<T> * & last)
{
    if (last->data.rtype == NODE_LINK && !last->rc) {
        last->data.rtype = THREAD_LINK;
        last->rc = node;
    }
    if (node->data.ltype == NODE_LINK && !node->lc) {
        node->data.ltype = THREAD_LINK;
        node->lc = last;
    }
    last = node;
}

template <typename T>
void _build_pre_threading(threading_node<T> * root, threading_node<T> * & last)
{
    if (!root) {
        return;
    }

    _connect_threading_link(root, last);
    if (root->data.ltype == NODE_LINK) {
        _build_pre_threading(root->lc, last);
    }
    if (root->data.rtype == NODE_LINK) {
        _build_pre_threading(root->rc, last);
    }
}

template <typename T>
void _build_in_threading(threading_node<T> * root, threading_node<T> * & last)
{
    if (!root) {
        return;
    }

    if (root->data.ltype == NODE_LINK) {
        _build_in_threading(root->lc, last);
    }
    _connect_threading_link(root, last);
    if (root->data.rtype == NODE_LINK) {
        _build_in_threading(root->rc, last);
    }
}

template <typename T>
void _build_post_threading(threading_node<T> * root, threading_node<T> * & last)
{
    if (!root) {
        return;
    }

    if (root->data.ltype == NODE_LINK) {
        _build_post_threading(root->lc, last);
    }
    if (root->data.rtype == NODE_LINK) {
        _build_post_threading(root->rc, last);
    }
    _connect_threading_link(root, last);
}

template <typename T>
threading_node<T> *
_threading_build(threading_node<T> * root, threading_type type)
{
    threading_node<T> * new_root = new threading_node<T>();
    new_root->data.ltype = NODE_LINK;
    new_root->data.rtype = THREAD_LINK;
    threading_node<T> * tail = new_root;
    switch (type) {
        case PRE_ORDER_THREADING:
            _build_pre_threading(root, tail);
            break;
        case IN_ORDER_THREADING:
            _build_in_threading(root, tail);
            break;
        case POST_ORDER_THREADING:
            _build_post_threading(root, tail);
            break;
        default:
            std::cerr << "invalid threading type: " << type << '\n';
            break;
    }

    if (tail != new_root) {
        new_root->lc = root;
        new_root->rc = tail;
        if (!tail->rc) {
            tail->data.rtype = THREAD_LINK;
            tail->rc = new_root;
        }
    }

    return new_root;
}

template <typename T>
threading_node<T> * 
read_threading(threading_type t_type, format_type f_type = HIERARCHY_FORMAT)
{
    threading_node<T> * root = read< _threading<T> >(f_type);
    return _threading_build(root, t_type);
}

template <typename T>
void _print_pre_threading(threading_node<T> * root, bool reverse)
{
    if (!reverse) {
        threading_node<T> * p = root->lc;
        while (p != root) {
            std::cout << p->data.data << ' ';
            if (p->data.ltype == NODE_LINK) {
                p = p->lc;
            } else {
                p = p->rc;
            }
        }
        std::cout << '\n';
    } else {
        std::cerr << "reverse visit not support in pre-order-threading\n";
        return;
    }
}

template <typename T>
void _print_in_threading(threading_node<T> * root, bool reverse)
{
    if (!reverse) {
        threading_node<T> * p = root->lc;
        // init
        while (p->data.ltype == NODE_LINK) {
            p = p->lc;
        }

        while (p != root) {
            std::cout << p->data.data << ' ';
            if (p->data.rtype == THREAD_LINK) {
                p = p->rc;
            } else {
                p = p->rc;
                while (p->data.ltype == NODE_LINK) {
                    p = p->lc;
                }
            }
        }
    } else {
        threading_node<T> * p = root->rc;
        while (p != root) {
            std::cout << p->data.data << ' ';
            if (p->data.ltype == THREAD_LINK) {
                p = p->lc;
            } else {
                p = p->lc;
                while (p->data.rtype == NODE_LINK) {
                    p = p->rc;
                }
            }
        }
    }
    std::cout << '\n';
}

template <typename T>
void _print_post_threading(threading_node<T> * root, bool reverse)
{
    if (!reverse) {
        std::cerr << "reverse visit not support in post-order-threading\n";
        return;
    } else {
        threading_node<T> * p = root->rc;
        while (p != root) {
            std::cout << p->data.data << ' ';
            if (p->data.rtype == NODE_LINK) {
                p = p->rc;
            } else {
                p = p->lc;
            }
        }
        std::cout << '\n';
    }
}

template <typename T>
void print_threading(threading_node<T> * root, 
        threading_type type, bool reverse = false)
{
    if (!root || !root->lc) {
        std::cout << "[empty threading tree]\n";
        return;
    }

    switch (type) {
        case PRE_ORDER_THREADING:
            _print_pre_threading(root, reverse);
            break;
        case IN_ORDER_THREADING:
            _print_in_threading(root, reverse);
            break;
        case POST_ORDER_THREADING:
            _print_post_threading(root, reverse);
            break;
        default:
            std::cerr << "invalid threading type: " << type << '\n';
            break;
    }
}

template <typename T>
void _de_threading(threading_node<T> * root)
{
    if (root) {
        if (root->data.ltype == THREAD_LINK) {
            root->lc = NULL;
        } else {
            _de_threading(root->lc);
        }
        if (root->data.rtype == THREAD_LINK) {
            root->rc = NULL;
        } else {
            _de_threading(root->rc);
        }
    }
}

template <typename T>
void free_threading(threading_node<T> * root)
{
    _de_threading(root);
    delete root;
}
