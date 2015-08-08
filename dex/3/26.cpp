// @mission: from 26.png

#include <iostream>

double m_sqrt(double a);
double m_sqrt2(double a);

int main()
{
    double a = 0.0;
    std::cin >> a;

    double r1 = m_sqrt(a);
    double r2 = m_sqrt2(a);

    std::cout << r1 << "\n" << r2 << '\n';

    return 0;
}
