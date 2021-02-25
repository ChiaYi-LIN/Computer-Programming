#include <iostream>
#include "DigitalWatch.h"
using namespace std;

void setWatch(DigitalWatch&, int, int, int);

int main()
{
    cout<<"[Initialize]"<<endl;
    DigitalWatch my_watch;
    cout<<"Current Time: "<<my_watch<<endl;

    cout<<endl<<"[Set Time]"<<endl;
    setWatch(my_watch, 100, 200, 300);
    setWatch(my_watch, 12, 30, 0);

    cout<<endl<<"[Update Time]"<<endl;
    int sec_elapsed;
    cout<<"Seconds Elapsed: ";
    cin>>sec_elapsed;
    my_watch = my_watch + sec_elapsed;

    cout<<"Updated Time: "<<my_watch<<endl;

    return 0;
}

void setWatch(DigitalWatch& w, int h, int m, int s)
{
    if(w.setTime(h, m, s))
        cout<<"After Setting: "<<w<<endl;
    else
        cout<<h<<":"<<m<<":"<<s<<" is not a legal setting!"<<endl;
}
