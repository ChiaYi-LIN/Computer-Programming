#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

double square_root(int, int, int);
double square_root(double, double, double);

int main()
{
    int a1 = 0, a2 = 0, a3 = 0;
    double b1 = 0, b2 = 0, b3 = 0;
    cin >> a1 >> a2 >> a3;
    square_root(a1, a2, a3);
    cin >> b1 >> b2 >> b3;
    square_root(b1, b2, b3);

    return 0;
}

double square_root(int a1, int a2, int a3)
{
    cout << fixed << setprecision(1) << sqrt(a1*a2*a3) << endl;
    return 0.0;
}

double square_root(double b1, double b2, double b3)
{
    cout << fixed << setprecision(1) << sqrt(b1*b2*b3) << endl;
    return 0.0;
}
