#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int original_num = 0, number = 0, base = 0;
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    cout << "Please input a positive decimal number: ";
    cin >> original_num;
    while (original_num <= 0)
    {
        cout << "Please input a positive decimal number: ";
        cin >> original_num;
    }
    number = original_num;

    cout << "Please input the desired base: ";
    cin >> base;
    while (base < 2 || base > 16)
    {
        cout << "Please input the desired base: ";
        cin >> base;
    }

    int r = 0;
    int output[100] = {};
    int counter = 0;

    while (number >= base)
    {
        r = number % base;
        output[counter++] = r;
        number = number / base;
    }
    output[counter] = number;

    cout << "\"" << original_num << "\" in base-10 system = \"";
    while (counter >= 0) cout << hex[ output[counter--] ];
    cout << "\" in base-" << base << " system" << endl;

    return 0;
}
