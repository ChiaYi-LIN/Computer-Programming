#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    char the_map[8][15] = {'0'};
    int move_x = 0, move_y = 0;
    int posi_x = 0, posi_y = 0;
    int ori_x = 0, ori_y = 0;
    int i = 0, j = 0;
    //#
    for (i=0; i<15; i++)
    {
        the_map[0][i] = '#';
    }
    for (i=0; i<15; i++)
    {
        the_map[7][i] = '#';
    }
    for (i=1; i<7; i++)
    {
        the_map[i][0] = '#';
    }
    for (i=1; i<7; i++)
    {
        the_map[i][14] = '#';
    }

    //num
    for (i=1; i<6; i++)
    {
        the_map[i][2] = '0' + 6 - i;
    }
    for (i=4; i<14; i+=2)
    {
        the_map[6][i] = '0'+ (i/2-1);
    }

    //-
    for (i=1; i<6; i++)
    {
        for (j=4; j<14; j+=2)
        {
            the_map[i][j] = '-';
        }
    }

    //X, *
    the_map[6][2] = 'X';
    the_map[1][12] = '*';

    cout << "Try to find the treasure! * is the position of the treasure." << endl;
    cout << "You are at the origin. X is your position." << endl;

    for (i=0; i<8; i++)
    {
        for (j=0; j<15; j++)
        {
            cout << setw(1) << the_map[i][j];
        }
        cout << endl;
    }

    posi_x = 2;
    posi_y = 6;
    while (the_map[1][12]!='X')
    {
        cout << "Move on direction of x, y = ";
        cin >> move_x >> move_y;

        ori_x = posi_x;
        ori_y = posi_y;
        posi_x += move_x * 2;

        if (posi_x<=2)
        {
            posi_x = 2;
        }
        else if (posi_x>=12)
        {
            posi_x = 12;
        }
        the_map[ori_y][ori_x] = 'N';
        the_map[ori_y][posi_x] = 'X';

        if (the_map[1][12]=='X')
        {
            goto output;
        }


        posi_y -= move_y;
        if (posi_y<=1)
        {
            posi_y = 1;
        }
        else if (posi_y>=6)
        {
            posi_y = 6;
        }

        the_map[ori_y][posi_x] = 'N';
        the_map[posi_y][posi_x] = 'X';


        output:
        //num
        if (the_map[6][2]!='X')
        {
            the_map[6][2] = '0';
        }

        for (i=1; i<6; i++)
        {
            if (the_map[i][2]!='X')
            the_map[i][2] = '0' + 6 - i;
        }
        for (i=4; i<14; i+=2)
        {
            if (the_map[6][i]!='X')
            the_map[6][i] = '0'+ (i/2-1);
        }
        //-
        for (i=1; i<6; i++)
        {
            for (j=4; j<14; j+=2)
            {
                if (the_map[i][j]!='X')
                the_map[i][j] = '-';
            }
        }
        //*
        if (the_map[1][12]!='X')
        {
            the_map[1][12] = '*';
        }
        cout << setw(8) << "|" << endl;
        cout << setw(8) << "|" << endl;
        cout << setw(8) << "V" << endl;
        //output map
        for (i=0; i<8; i++)
        {
            for (j=0; j<15; j++)
            {
                cout << setw(1) << the_map[i][j];
            }
            cout << endl;
        }
        cout << "Your position is (" << posi_x/2-1 << "," << 6-posi_y << ")" << endl;

        if (the_map[1][12]=='X')
        {
            cout << "SUCCESSFUL!";
            break;
        }
    }

    return 0;
}
