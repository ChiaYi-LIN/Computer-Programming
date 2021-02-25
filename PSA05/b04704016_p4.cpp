#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int level = 0, row = 0, col = 0, i = 0, j = 0;
    cout << "Input the level of Pascal's diamond: ";
    cin >> level;
    row = level + 1;
    col = 2 * level + 1;
    int diamond[row][col] = {};
    diamond[0][level] = 1;


    for (i = 1; i < row; i++)
    {
        for (j = 0; j < col ; j++)
        {
        diamond[i][j] = diamond[(i-1+row)%row][(j-1+col)%col] + diamond[(i-1+row)%row][(j+1)%col];
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
        if (diamond[i][j] == 0)
        {
        cout << setw(4) << "";
        }
        else if (diamond[i][j] != 0)
        {
        cout << setw(4) << diamond[i][j];
        }
        }
    cout << endl;
    }

    for (i = row - 2; i >= 0; i--)
    {
        for(j = 0; j < col; j++)
        {
        if (diamond[i][j] == 0)
        {
        cout << setw(4) << "";
        }
        else if (diamond[i][j] != 0)
        {
        cout << setw(4) << diamond[i][j];
        }
        }
    cout << endl;
    }

    return 0;
}
