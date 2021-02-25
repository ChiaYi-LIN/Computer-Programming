#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int A = 1, B = 1;

    for (B; B <= 9; B++)
    {

    while (A <= 5)
    {
    cout << A <<"*" << B << "=" << setw(2) << A*B << "\t";
    A++;
    }

    cout << endl;
    A = 1;
    }



    return 0;
}
