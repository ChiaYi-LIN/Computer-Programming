#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    long long int input = 0;
    int i = 0, m = 0, n = 0, x = 0;
    char input_num[10] = {};
    char digit[5][50] = {'0'};

    cout << "Please input a positive integer (digit<10): ";
    cin >> input;

    while (input >= 10000000000)
    {
        cout << "Please input a positive integer (digit<10): ";
        cin >> input;
    }

    while (input >= 10)
    {
        input_num[i] = '0' + (input % 10);
        input /= 10;
        i++;
    }
    input_num[i] = '0' + input;
    x = i+1;

    for (i; i>=0; i--)
    {
            if (input_num[i] == '0' + 0)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n] = '|';
            digit[1][n+3] = '|';
            digit[2][n] = '|';
            digit[2][n+3] = '|';
            digit[3][n] = '|';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 1)
            {
            digit[1][n+3] = '|';
            digit[2][n+3] = '|';
            digit[3][n+3] = '|';
            }
            else if (input_num[i] == '0' + 2)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n+3] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 3)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n+3] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 4)
            {
            digit[1][n] = '|';
            digit[1][n+3] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n+3] = '|';
            }
            else if (input_num[i] == '0' + 5)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 6)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n] = '|';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 7)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n+3] = '|';
            digit[2][n+3] = '|';
            digit[3][n+3] = '|';
            }
            else if (input_num[i] == '0' + 8)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n] = '|';
            digit[1][n+3] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n] = '|';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
            else if (input_num[i] == '0' + 9)
            {
            digit[0][n+1] = '-';
            digit[0][n+2] = '-';
            digit[1][n] = '|';
            digit[1][n+3] = '|';
            digit[2][n+1] = '-';
            digit[2][n+2] = '-';
            digit[3][n+3] = '|';
            digit[4][n+1] = '-';
            digit[4][n+2] = '-';
            }
        n += 5;
    }

    for (m=0; m<5; m++)
    {
        for (n=0; n<50; n++)
        {
            if (digit[m][n]!='0')
            {
                cout << digit[m][n];
            }
            else if (digit[m][n]=='0')
            {
                cout << ' ';
            }

        }
        cout << endl;
    }

    return 0;
}
