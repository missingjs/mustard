#include <iostream>
#include "common/qu.h"
using namespace mustard;

void print_k_fib(int k, int max)
{
    if (k < 1 || max < 0) {
        return;
    }

    if (k == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    if (max == 0) {
        for (int i = 1; i < k; ++i) {
            std::cout << 0 << ' ';
        }
        std::cout << std::endl;
        return;
    }

    qu::cyc_queue<int> q(k);
    for (int i = 1; i < k; ++i) {
        q.push(0);
    }
    q.push(1);

    int acc = 1, next = 1;
    while (next <= max) {
        int f = q.front();
        q.pop();
        std::cout << f << ' ';
        acc -= f;
        q.push(next);
        acc += next;
        next = acc;
    }

    while (!q.empty()) {
        std::cout << q.front() << ' ';
        q.pop();
    }
    std::cout << '\n';
}
