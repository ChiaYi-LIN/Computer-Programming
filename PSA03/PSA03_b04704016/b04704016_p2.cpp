#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int A, B, S, C, Ci, Co;

    cout << "Please input A, B for halfadder:" << endl;

    cout << "A = ";
    cin >> A;
    while (A != 0 && A != 1)
    {
    cin >> A;
    }

    cout << "B = ";
    cin >> B;
    while (B != 0 && B != 1)
    {
    cin >> B;
    }

    cout << "Half adder output:" << endl;

    cout << "S = " ;
    if (A != B)
    {
    cout << 1;
    }
    else
    {
    cout << 0;
    }
    cout << endl;

    cout << "C = " ;
    if (A == 1 && B == 1)
    {
    cout << 1;
    }
    else
    {
    cout << 0;
    }

    cout << endl;

    cout << "Please input A,B,Ci for fulladder:" << endl;

    cout << "A = ";
    cin >> A;
    while (A != 0 && A != 1)
    {
    cin >> A;
    }

    cout << "B = ";
    cin >> B;
    while (B != 0 && B != 1)
    {
    cin >> B;
    }

    cout << "Ci = ";
    cin >> Ci;
    while (Ci != 0 && Ci != 1)
    {
    cin >> Ci;
    }

    cout << "Full adder output:" << endl;

    cout << "S = ";
    if ((A == B && Ci == 0) || (A != B && Ci == 1))
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }

    cout << endl;

    cout << "Co = ";
    if ((A == 0 || B == 0) && (A == B || Ci == 0))
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }

    return 0;
}
