#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int A[3][5] = {};
    int B[5][2] = {};
    int C[3][2] = {};

    cout << "Please input matrix A in row wise (3 rows, 5 columns):" << endl;
    for (int row_A=0; row_A<3; row_A++)
    {
        for (int col_A=0; col_A<5; col_A++) cin >> A[row_A][col_A];
    }
    cout << "Please input matrix B in row wise (5 rows, 2 columns):" << endl;
    for (int row_B=0; row_B<5; row_B++)
    {
        for (int col_B=0; col_B<2; col_B++) cin >> B[row_B][col_B];
    }

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<5; k++)
            {
            C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Matrix C (C = A * B):" << endl;
    for (int row_C=0; row_C<3; row_C++)
    {
        for (int col_C=0; col_C<2; col_C++)
        {
        cout << C[row_C][col_C] << "\t";
        }
    cout << endl;
    }
    return 0;
}
