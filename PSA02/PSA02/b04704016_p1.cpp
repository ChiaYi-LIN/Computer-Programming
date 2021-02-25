#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    char test = 'H';
    printf("printf test \t: %d, %o, %x, %c", test, test, test, test);
    cout << endl;
    int itest = test;
    cout << "cout test \t: " << dec << itest << ", " << oct << itest << ", " << hex << itest << ", " << test << endl;
    cout << dec << endl;

    double test2 = 10.000789;
    cout << "test2 value: " << setprecision(6) << test2 << endl;

    return 0;
}
