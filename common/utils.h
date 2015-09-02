#ifndef MUSTARD_UTILS_H
#define MUSTARD_UTILS_H 1

#include <iostream>

namespace mustard {
namespace utils {

template <typename Iter>
void print_list(Iter begin, Iter end)
{
    for (Iter i(begin); i != end; ++i) {
        std::cout << *i << ' ';
    }
    std::cout << '\n';
}

} // namespace ::mustard::utils
} // namespace ::mustard

#endif   // ifndef MUSTARD_UTILS_H
