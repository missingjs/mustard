#ifndef MUSTARD_MATRIX_H
#define MUSTARD_MATRIX_H 1

#include <iostream>

namespace mustard {

namespace mtx {

template <typename T>
struct matrix
{
    int  row;
    int  col;
    T  * data;

    matrix(int r, int c)
        : row(r), col(c), data(new T[r*c])
    {}

    ~matrix()
    {
        delete[] data;
    }

    T get(int r, int c) const
    {
        return data[r * col + c];
    }

    void set(int r, int c, T d)
    {
        data[r * col + c] = d;
    }

};

template <typename T>
matrix<T> * read()
{
    int r = 0, c = 0;
    std::cin >> r >> c;

    if (r <= 0 || c <= 0) {
        return NULL;
    }

    matrix<T> * m = new matrix<T>(r,c);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            T t;
            std::cin >> t;
            m->set(i,j,t);
        }
    }

    return m;
}

template <typename T>
void print(const matrix<T> * m)
{
    for (int i = 0; i < m->row; ++i) {
        for (int j = 0; j < m->col; ++j) {
            std::cout << m->get(i,j) << ' ';
        }
        std::cout << '\n';
    }
}

template <typename T>
void free(matrix<T> * m)
{
    delete m;
}

} // namespace ::mustard::mtx

} // namespace ::mustard

#endif
