#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float s, a, b, c;
    cout << "Please input 3 length of the sides of a triangle:" << endl;
    cout << "a = ";
    cin >> a ;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    s = (a+b+c)/2;

    if (sqrt(s*(s-a)*(s-b)*(s-c)) > 0)
    {
        cout << "The area of the triangle is: " << sqrt(s*(s-a)*(s-b)*(s-c)) << endl;
    }
    else
    {
        cout << "The lengths of the sides cannot be a triangle!";
    }

    return 0;
}
