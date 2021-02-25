#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int A=0, B=0;
    char cor_num[4] = {};
    char com_num[4] = {};

    cout << "Correct number: ";
    for (int i=0; i<4; i++)
    {
    cin >> cor_num[i];
    }

    cout << "Compared number: ";
    for (int j=0; j<4; j++)
    {
    cin >> com_num[j];
    }

    for (int k=0; k<4; k++)
    {
        if (cor_num[k] == com_num[k])
        {
            A += 1;
        }
        else if ((cor_num[k] == com_num[0]) || (cor_num[k] == com_num[1]) || (cor_num[k] == com_num[2]) || (cor_num[k] == com_num[3]))
        {
            B += 1;
        }
    }
    cout << "Result: ";
    cout << A << "A" << B << "B";

return 0;
}
