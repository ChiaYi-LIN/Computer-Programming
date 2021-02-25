#include <iostream>
#include "DigitalWatch.h"
using namespace std;

void displayWatch(DigitalWatch&);
void setWatch(DigitalWatch&, int, int, int);

int main()
{
    cout<<"[Initialize]"<<endl;
    DigitalWatch my_watch;
    cout<<"Current Time: ";
    displayWatch(my_watch);

    cout<<endl<<"[Set Time]"<<endl;
    setWatch(my_watch, 100, 200, 300);
    setWatch(my_watch, 12, 30, 0);

    cout<<endl<<"[Update Time]"<<endl;
    int sec_elapsed;
    cout<<"Seconds Elapsed: ";
    cin>>sec_elapsed;
    my_watch.update(sec_elapsed);

    cout<<"Updated Time: ";
    displayWatch(my_watch);

    return 0;
}

void displayWatch(DigitalWatch& w)
{
    w.display(0);
    cout<<" (";
    w.display(1);
    cout<<")"<<endl;
}

void setWatch(DigitalWatch& w, int h, int m, int s)
{
    if(w.setTime(h, m, s))
    {
        cout<<"After Setting: ";
        displayWatch(w);
    }
    else
        cout<<h<<":"<<m<<":"<<s<<" is not a legal setting!"<<endl;
}
