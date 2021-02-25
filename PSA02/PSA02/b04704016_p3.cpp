#include <iostream>

using namespace std;

#define message "go together"
#define message2 "slip away"

int main()
{

    cout <<"Let me tell you something interesting!!"<<endl;
    int go;
    go = 1798;
    cout << go << " means \"" << message <<"\" in Chinese."<< endl;
    int leave = 6868;
    int & away = leave;
    cout << away << " means \"" << message2 <<"\" in Chinese."<< endl;

    return 0;
}

