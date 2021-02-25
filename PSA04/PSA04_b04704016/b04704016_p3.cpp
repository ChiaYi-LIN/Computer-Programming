#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int array[10];
    cout << "The grades of 10 students TA typed (in reverse order):" << endl;

    for (int i = 0; i <= 9; i++) cin >> array[i];

    cout << "Correct order" << endl;
    cout << "Number\tGrades" << endl;

    for (int n = 0; n <=9; n++)
    {
    cout << setw(2) << n + 1 << "\t" << setw(3) <<array[9 - n] << endl;
    }

    return 0;
}
