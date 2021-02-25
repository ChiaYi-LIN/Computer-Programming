#include <iostream>
#include <cstdio>

using namespace std;

namespace EE1004
{
    int a = 20;
    double b = 2.45689;
    char c = 'g';
}

using namespace EE1004;

int main()
{
    cout << "a variable: " << a << ", " << sizeof(a) << endl;
    cout << "a variable: " << b << ", " << sizeof(b) << endl;
    cout << "a variable: " << c << ", " << sizeof(c) << endl;
    return 0;
}

