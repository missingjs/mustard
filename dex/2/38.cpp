// @brief: 参见38.png

#include "common/array.h"
#include "common/dlist.h"
#include "38_cell.h"
using namespace mustard;

typedef cell<int> cell_t;
typedef dlist::node<cell_t> node_t;

// @return: 成功访问元素个数
int visit(node_t * head, const int * v, int len);

template <typename T>
std::istream & operator >> (std::istream & in, cell<T> & c)
{
    c.freq = 0;
    in >> c.data;
    return in;
}

template <typename T>
std::ostream & operator << (std::ostream & out, const cell<T> & c)
{
    out << '(' << c.data << ',' << c.freq << ')';
    return out;
}

int main()
{
    node_t * h = dlist::read<cell_t>();
    node_t * tail = dlist::make_circular(h);

    node_t head;
    if (tail) {
        node_t * ph = tail->next;
        head.next = ph;
        ph->prev = &head;
        head.prev = tail;
        tail->next = &head;
    } else {
        head.next = head.prev = &head;
    }

    int len = 0;
    int * v = array::read<int>(len);

    int vc = visit(&head, v, len);
    std::cout << "visit times: " << vc << '\n';

    array::free(v);

    if (head.next != &head) {
        head.prev->next = NULL;
    } else {
        head.next = NULL;
    }
    dlist::print(head.next);
    dlist::free(head.next);

    return 0;
}
