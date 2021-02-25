#include <iostream>
#include <ctime>
#include "DigitalWatch.h"
using namespace std;

DigitalWatch::DigitalWatch()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    hour = ltm->tm_hour;
    minute = ltm->tm_min;
    second = ltm->tm_sec;
}

bool DigitalWatch::setTime(int h, int m, int s)
{
    if(h>=0 && h<24 && m>=0 && m<60 && s>=0 && s<60)
    {
        hour = h;
        minute = m;
        second = s;
        return true;
    }
    return false;
}

void DigitalWatch::update(int s)
{
    int ds = second + s%60;
    int dm = minute + (s%3600)/60;
    int dh = hour + s/3600;

    second = ds%60;
    minute = ds/60+dm%60;
    hour = dm/60+dh%24;
}

void DigitalWatch::display(bool twelve)
{
    int show_hour = hour;
    if(twelve)
    {
        show_hour=show_hour%12;
        if(hour==0 || hour==12)
            show_hour=12;
    }
    if(show_hour<10)
        cout<<"0";
    cout<<show_hour<<":";

    if(minute<10)
        cout<<"0";
    cout<<minute<<":";

    if(second<10)
        cout<<"0";
    cout<<second;

    if(twelve)
    {
        if(hour<12)
            cout<<" AM";
        else
            cout<<" PM";
    }
}

DigitalWatch DigitalWatch::operator+ (const int s)
{
    DigitalWatch a;
    int ds = second + s%60;
    int dm = minute + (s%3600)/60;
    int dh = hour + s/3600;

    second = ds%60;
    minute = ds/60+dm%60;
    hour = (dm/60+dh)%24;

    a.hour = hour;
    a.minute = minute;
    a.second = second;

    return a;
}

ostream& operator<<(ostream &output, const DigitalWatch &r)
{

    int show_hour = r.hour;

    if(1)
    {
        show_hour=show_hour%12;
        if(r.hour==0 || r.hour==12)
            show_hour=12;
    }
    if(show_hour<10)
        output<<"0";
    output<<show_hour<<":";

    if(r.minute<10)
        output<<"0";
    output<<r.minute<<":";

    if(r.second<10)
        output<<"0";
    output<<r.second;

    if(1)
    {
        if(r.hour<12)
            cout<<" AM";
        else
            cout<<" PM";
    }



    return output;
}
