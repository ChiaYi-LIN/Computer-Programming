#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int output[99999999] = {};
int output_1 [99999999] = {};
int output_2 [99999999] = {};

int main()
{
    int origin_num = 0, number = 0, base = 0, n = 0, i = 0;

    cout << "(a)" << endl;
    cout << "Please input a positive integer: ";
    cin >> origin_num;
    number = origin_num;

    for (n=2; n<=number; n++)
    {
        while ((number%n)==0)
        {
            number /= n;
            output[n] += 1;
        }
    }

    cout << origin_num << " =";

    for (i=2; i<(n-1); i++)
    {
        if (output[i]!=0)
        {
            if (output[i]==1)
            {
                cout << " " << i << " x";
            }
            else if (output[i]!=1)
            {
                cout << " " << i << "^" << output[i] << " x";
            }
        }
    }

    if (output[n-1]==1)
        {
            cout << " " << n-1;
        }
    else if (output[n-1]!=1)
        {
            cout << " " << n-1 << "^" << output[n-1];
        }

    cout << endl;

    int ori_num_1 = 0, ori_num_2 = 0, num_1 = 0, num_2 = 0;
    int gcd = 1, lcm = 1;
    int a = 0, b = 0, c = 0;
    cout << "(b)" << endl;
    cout << "Please input two positive integers: ";
    cin >> ori_num_1 >> ori_num_2;

    num_1 = ori_num_1;
    num_2 = ori_num_2;

    for (a=2; a<=num_1; a++)
    {
        while ((num_1%a)==0)
        {
            num_1 /= a;
            output_1[a] += 1;
        }
    }

    for (b=2; b<=num_2; b++)
    {
        while ((num_2%b)==0)
        {
            num_2 /= b;
            output_2[b] += 1;
        }
    }

    for (c=2; (c<=a)&&(c<=b); c++)
    {
        if ((output_1[c]>0)&&(output_2[c]>0))
        {
            if(output_1[c]>=output_2[c])
            {
                gcd = gcd * pow(c, output_2[c]);
            }
            else if(output_1[c]<output_2[c])
            {
                gcd = gcd * pow(c, output_1[c]);
            }
        }
    }

        for (c=2; (c<=a)||(c<=b); c++)
    {
        if ((output_1[c]>0)||(output_2[c]>0))
        {
            if(output_1[c]>=output_2[c])
            {
                lcm = lcm * pow(c, output_1[c]);
            }
            else if(output_1[c]<output_2[c])
            {
                lcm = lcm * pow(c, output_2[c]);
            }
        }
    }

    cout << "gcd (" << ori_num_1 << "," << ori_num_2 << ") = " << gcd << endl;
    cout << "lcm (" << ori_num_1 << "," << ori_num_2 << ") = " << lcm << endl;

    return 0;
}
