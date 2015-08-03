#include <stddef.h>
#include <iostream>

void se(const int * input, int len, int i, int * stack, int top, int * output, int j);

void seq_exhaust(const int * arr, int len)
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
