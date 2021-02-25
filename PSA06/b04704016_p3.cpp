#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int *a, *b;
    int vec_1_length = 0, vec_2_length = 0;
    int i = 0;

    cout << "Please input the first vector length: ";
    cin >> vec_1_length;

    a = new int[vec_1_length];

    cout << "Please input the second vector length: ";
    cin >> vec_2_length;

    b = new int[vec_2_length];

    cout << "Please input elements of first vector (" << vec_1_length << " elements): ";
    for (i=0; i<vec_1_length; i++)
    {
        cin >> a[i];
    }

    cout << "Please input elements of second vector (" << vec_2_length << " elements): ";
    for (i=0; i<vec_2_length; i++)
    {
        cin >> b[i];
    }

    cout << "[ ";
    for (i=0; i<vec_1_length; i++)
    {
        cout << a[i] << " ";
    }
    cout << "] + [ ";
    for (i=0; i<vec_2_length; i++)
    {
        cout << b[i] << " ";
    }
    cout << "] = [ ";
    for (i=0; i<vec_1_length; i++)
    {
        cout << a[i] << " ";
    }
    for (i=0; i<vec_2_length; i++)
    {
        cout << b[i] << " ";
    }
    cout << "]" << endl;

    delete [] a;
    delete [] b;

    return 0;
}
