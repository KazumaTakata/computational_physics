#include <iostream>
#include <math.h>

using namespace std;
double second_derivative(double (*f)(double), double x, double h);

double myexp(double x);

int main()
{
    cout << "hello";

    double ee = second_derivative(exp, 1, 0.01);
    cout << ee;

    return 0;
}

double second_derivative(double (*f)(double), double x, double h)
{
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double myexp(double x)
{
    return exp(x);
}