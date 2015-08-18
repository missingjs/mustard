#ifndef MUSTARD_MATRIX2_H
#define MUSTARD_MATRIX2_H

#include <iosfwd>

namespace mustard {

namespace matrix {

template <typename T>
class common_matrix
{
private:

    T * _data;

    int _row, _col;

public:

    common_matrix(int row, int col);

    ~common_matrix();

    common_matrix(const common_matrix<T> & m);

    common_matrix<T> & operator= (const common_matrix<T> & m);

    void swap(common_matrix<T> & m);

    int row() const { return _row; }

    int col() const { return _col; }

    struct _matrix_row
    {
        int _row;

        common_matrix<T> & _mx;

        _matrix_row(int row, common_matrix<T> & mx);

        _matrix_row(const _matrix_row & r);

        T & operator[] (int col);

    private:
        _matrix_row & operator= (const _matrix_row & r);

    };

    struct _const_matrix_row
    {
        int _row;

        const common_matrix<T> & _mx;

        _const_matrix_row(int row, const common_matrix<T> & mx);

        _const_matrix_row(const _const_matrix_row & r);

        T operator[] (int col) const;

    private:
        _const_matrix_row & operator= (const _const_matrix_row & r);
    };

    _matrix_row operator[] (int row);

    _const_matrix_row operator[] (int row) const;

private:

    T & d(int r, int c);

    T d(int r, int c) const;

};

template <typename T>
std::istream & operator>> (std::istream & in, common_matrix<T> & m);

template <typename T>
std::ostream & operator<< (std::ostream & out, const common_matrix<T> & m);

template <typename T>
common_matrix<T> * read();

template <typename T>
void print(const common_matrix<T> * m);

template <typename T>
void print(const common_matrix<T> & m);

} // namespace ::mustard::matrix

} // namespace ::mustard

#include "__common_matrix_impl.h"

#endif  // ifndef MUSTARD_MATRIX2_H
