// @brief: 参见39.png

#include "def.h"
using namespace mustard::dex_2;

int evaluate(sq_poly<int,int> * poly, int x);

int main()
{
    sq_poly<int,int> * poly = read_poly<int,int>();

    int x;
    std::cin >> x;

    int result = evaluate(poly, x);

    std::cout << "result: " << result << std::endl;

    free_poly(poly);

    return 0;
}
