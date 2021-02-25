#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int row_A = 0, col_A = 0, num_A = 0;
    int row_B = 0, col_B = 0, num_B = 0;
    int i = 0, j = 0, k = 0;
    cout << "Please input size of matrix A: ";
    cin >> row_A >> col_A;
    int A[row_A][col_A] = {};
    num_A = row_A * col_A;
    cout << "Please input " << num_A << " elements of matrix A: ";
    for(i=0; i<row_A; i++)
    {
        for(j=0; j<col_A; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Please input size of matrix B: ";
    cin >> row_B >> col_B;
    int B[row_B][col_B] = {};
    num_B = row_B * col_B;
    cout << "Please input " << num_B << " elements of matrix B: ";
    for(i=0; i<row_B; i++)
    {
        for(j=0; j<col_B; j++)
        {
            cin >> B[i][j];
        }
    }

    int C[row_A][col_B] = {};

    if (col_A!=row_B)
    {
        cout << "Wrong size!";
    }
    else
    {
        for(i=0; i<row_A; i++)
        {
            for(j=0; j<col_B; j++)
            {
                for (k=0; k<col_A ;k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        for(i=0; i<row_A; i++)
        {
            for(j=0; j<col_B; j++)
            {
                cout << setw(8) << C[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
