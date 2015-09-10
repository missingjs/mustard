#include "common/array.h"
#include "common/utils.h"
#include "common/xstring.h"
using namespace mustard;

int main()
{
    int n = 0;
    int * arr = array::read<int>(n);

    utils::print_list(arr, arr + n);
    delete[] arr;

    char * line = xstring::read_line();
    std::cout << line << '\n';
    delete[] line;

    return 0;
}
