#include <iostream>
#include "time.h"
using namespace std;

Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

void Time::printStandard()
{
    if(hour >= 0 && hour < 12)
    {
        if(hour == 0)
        {
            cout << 12 << ":" << minute << ":" << second << " AM" << endl;
        }
        else
        {
            cout << hour << ":" << minute << ":" << second << " AM" << endl;
        }
    }
    else
    {
        if(hour == 12)
        {
            cout << 12 << ":" << minute << ":" << second << " PM" << endl;
        }
        else
        {
            cout << hour-12 << ":" << minute << ":" << second << " PM" << endl;
        }
    }
}

void Time::printUniversal()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

void Time::setTime(int ho, int mi, int se)
{
    hour = ho;
    minute = mi;
    second = se;
}
