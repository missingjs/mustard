#include <stddef.h>
#include <iostream>
#include <cstring>

void se(const int * input, int len, int i, int * stack, int top, int * output, int j);

struct step
{
    int * st;
    step * next;

    step(int n)
        : st(new int[n*2]), next(0)
    {}

    ~step()
    {
        delete[] st;
    }
};

void mk_steps(int n, int input, int stk, int * output, int p, step * & last)
{
    if (input == 0 && stk == 0) {
        step * st = new step(n);
        memcpy(st->st, output, sizeof(int) * n * 2);
        last->next = st;
        last = st;
        return;
    }

    if (input > 0) {
        output[p] = 1;
        mk_steps(n, input - 1, stk + 1, output, p+1, last);
    }

    if (stk > 0) {
        output[p] = 0;
        mk_steps(n, input, stk - 1, output, p+1, last);
    }
}

step * make_steps(int n)
{
    int inp = n, stk = 0;
    int * output = new int[n*2];

    step head(0), *last = &head;

    mk_steps(n, inp, stk, output, 0, last);

    delete[] output;

    return head.next;
}

void print_seq(const int * input, int len, step * st)
{
    int * stack = new int[len];
    int * output = new int[len];

    for (; st; st = st->next) {
        int i = 0, top = 0, p = 0;
        for (int k = 0; k < len * 2; ++k) {
            if (st->st[k] == 1) {
                stack[top++] = input[i++];
            } else {
                output[p++] = stack[--top];
            }
        }
        for (int k = 0; k < len; ++k) {
            std::cout << output[k] << ' ';
        }
        std::cout << std::endl;
    }

    delete[] stack;
    delete[] output;
}

void seq_exhaust_2(const int * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return;
    }

    step * st = make_steps(len);
    print_seq(arr, len, st);

    while (st) {
        step * t = st;
        st = st->next;
        delete t;
    }
}

void seq_exhaust_1(const int * arr, int len)
{
    if (arr == NULL || len <= 0) {
        return;
    }

    int * stack = new int[len];
    int * output = new int[len];

    se(arr, len, 0, stack, 0, output, 0);

    delete[] output;
    delete[] stack;
}

void seq_exhaust(const int * arr, int len)
{
    // seq_exhaust_1(arr, len);
    seq_exhaust_2(arr, len);
}

void se(const int * input, int len, int i, int * stack, int top, int * output, int j)
{
    if (i == len && top == 0) {
        for (int k = 0; k < len; ++k) {
            std::cout << output[k] << ' ';
        }
        std::cout << std::endl;
        return;
    }

    if (i < len) {
        stack[top] = input[i];
        se(input, len, i + 1, stack, top + 1, output, j);
    }

    if (top > 0) {
        output[j] = stack[top-1];
        se(input, len, i, stack, top - 1, output, j + 1);
        stack[top-1] = output[j];
    }
}
