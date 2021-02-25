#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int A[3][3] = {11, 22, 33, 22, 33, 44, 33, 44, 55};
    int B[3][3] = {3, 2, 1, 6, 5, 4, 9, 8, 7};
    int C[3][3];
    int i = 0, j = 0;
    int x , y;

    for (i; i < 3; i++)
    {
    while (j < 3)
    {
    C[i][j] = A[i][j] + B[i][j];
    j++;
    }
    j = 0;
    }

    cout << "Please input the index of matrix: " << endl;
    cin >> x >> y;
    cout << "The value of C" << x << y << " is " << C[x-1][y-1] << ".";

    return 0;
}
