#include <iostream>
using namespace std;

#include "common/array.h"
using namespace mustard;

bool insert(int * arr, int len, int x);

int main()
{
    int len = 0;
    cin >> len;
    
    int * arr = array_read<int>(len, len + 1);

    int x = 0;
    cin >> x;

    bool r = insert(arr, len, x);
    if (r) {
        ++len;
        array_print(arr, len);
    } else {
        cout << "NO insert" << endl;
    }

    array_free(arr);
    return 0;
}

bool insert(int * arr, int len, int x)
{
    if (arr == NULL || len < 0) {
        return false;
    }

    int i = 0;
    for (; i < len; ++i) {
        if (arr[i] >= x) {
            break;
        }
    }

    for (int j = len - 1; j >= i; --j) {
        arr[j + 1] = arr[j];
    }
    arr[i] = x;
    return true;
}
