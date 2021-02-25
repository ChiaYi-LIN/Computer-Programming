#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0, N;
    cout << "Please input the integer N: " << endl;
    cin >> N;

    while (N < 100 || N > 1500)
    {
    cout << "[WARNING]" << endl;
    cout << "The input integer N should be larger than 100 and less than 1500." << endl;
    cout << "Please input the integer N: " << endl;
    cin >> N;
    }

    for (N; N>0; N--)
    {
    sum = sum + N;
    }

    cout << "The sum is " << sum << "." << endl;


    return 0;
}
