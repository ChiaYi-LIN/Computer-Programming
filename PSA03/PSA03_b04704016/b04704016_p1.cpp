#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double number;
    cout << "Please input a number:";
    cin >> number;
    cout << "Ans1 = " << fixed << setprecision(3) << number + ceil(number) << endl;
    cout << "Ans2 = " << fixed << setprecision(3) <<
            (number + ceil(number)) - floor(number + ceil(number)) << endl;

    cout << "Ans3 = " << fixed << setprecision(3) <<
            ((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3)) << endl;
    cout << "Ans4 = " << fixed << setprecision(3) << (((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1 << endl;
    cout << "Ans5 = " << fixed << setprecision(3) << ((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1) *
            exp(((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1))  << endl;

    if ((((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1) *
            exp(((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1))) > 0)
    {
    cout << "Result:" << fixed << setprecision(3) << (((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1) *
            exp(((((number + ceil(number)) - floor(number + ceil(number))) /
            (log((number + ceil(number)) - floor(number + ceil(number))) / log(3))) + 1))) << endl;
    }
    else
    {
    cout << 0 << endl;
    }

    return 0;
}
