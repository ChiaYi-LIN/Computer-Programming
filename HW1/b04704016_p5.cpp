#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double well_height = 0;
    double cd_a = 0, sd_a = 0, dd_a = 0;
    double cd_b = 0, sd_b = 0, dd_b = 0;
    int day_a = 0, day_b = 0;
    double height_a = 0, height_b = 0;
    int i = 0;

    cout << "The well's height (meter): ";
    cin >> well_height;
    while (well_height<=0)
    {
        cout << "The well's height (meter): ";
        cin >> well_height;
    }

    cout << "Snail A's information:" << endl;
    cin >> cd_a;
    while (cd_a<=0)
    {
        cin >> cd_a;
    }
    cin >> sd_a;
    while (sd_a<0)
    {
        cin >> sd_a;
    }
    cin >> dd_a;
    while (dd_a<0)
    {
        cin >> dd_a;
    }

    cout << "Snail B's information:" << endl;
    cin >> cd_b;
    while (cd_b<=0)
    {
        cin >> cd_b;
    }
    cin >> sd_b;
    while (sd_b<0)
    {
        cin >> sd_b;
    }
    cin >> dd_b;
    while (dd_b<0)
    {
        cin >> dd_b;
    }

    for(i=1; height_a<well_height; i++)
    {
        height_a += cd_a;
        if (height_a>=well_height)
        {
            break;
        }
        height_a -= sd_a;
        if (height_a<=0)
        {
            break;
        }
        cd_a -= dd_a;
    }
    day_a = i;

    if (height_a>=well_height)
    {
        cout << "On day " << day_a << ": Snail A climb up to the top." << endl;
    }
    else if (height_a<=0)
    {
        cout << "On day " << day_a << ": Snail A slip down to the bottom." << endl;
    }

    for(i=1; height_b<well_height; i++)
    {
        height_b += cd_b;
        if (height_b>=well_height)
        {
            break;
        }
        height_b -= sd_b;
        if (height_b<=0)
        {
            break;
        }
        cd_b -= dd_b;
    }
    day_b = i;

    if (height_b>=well_height)
    {
        cout << "On day " << day_b << ": Snail B climb up to the top." << endl;
    }
    else if (height_b<=0)
    {
        cout << "On day " << day_b << ": Snail B slip down to the bottom." << endl;
    }

    return 0;
}
