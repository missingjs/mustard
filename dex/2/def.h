#ifndef DEX_2_H
#define DEX_2_H 1

#include "common/array.h"

namespace mustard {

namespace dex_2 {

template <typename C, typename E>
struct poly_term
{
    C coef;
    E exp;

    poly_term(const C & c = C(),
            const E & e = E()):
        coef(c), exp(e)
    {}
};

template <typename C, typename E>
std::istream & operator >> (std::istream & in, poly_term<C,E> & term)
{
    // format: (coef,exp)
    char ch = 0;
    in >> ch >> term.coef >> ch >> term.exp >> ch;
    return in;
}

template <typename C, typename E>
std::ostream & operator << (std::ostream & out, const poly_term<C,E> & term)
{
    // format: (coef,exp)
    out << '(' << term.coef << ',' << term.exp << ')';
    return out;
}

template <typename C, typename E>
struct sq_poly
{
    poly_term<C,E> * data;

    int              last;

    sq_poly():
        data(0), last(0)
    {}

    ~sq_poly()
    {
        delete[] data;
    }

    void print()
    {
        mustard::array::print(data, last);
    }
};

template <typename C, typename E>
sq_poly<C,E> * read_poly()
{
    typedef poly_term<C,E> term_t;

    int len;
    term_t * data = mustard::array::read<term_t>(len);

    sq_poly<C,E> * poly = new sq_poly<C,E>();
    poly->data = data;
    poly->last = len;
    return poly;
}

template <typename C, typename E>
void free_poly(sq_poly<C,E> * poly)
{
    delete poly;
}

} // namespace ::mustard::dex_2

} // namespace ::mustard

#endif
