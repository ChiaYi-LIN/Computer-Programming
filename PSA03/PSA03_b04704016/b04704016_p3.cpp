#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int16_t score;
    cout << "Please input a score(0~100): ";
    cin >> score;

    while ( (score >= 0 && score <= 100) != true )
    {
        cin >> score;
    }

    if (score == 100)
    {
        score = 1;
    }
    else if (score >= 90 && score <= 99)
    {
        score = 2;
    }
    else if (score >= 80 && score <= 89)
    {
        score = 3;
    }
    else if (score >= 70 && score <= 79)
    {
        score = 4;
    }
    else if (score >= 60 && score <= 69)
    {
        score = 5;
    }
    else if (score >= 50 && score <= 59)
    {
        score = 6;
    }
    else if (score < 50)
    {
        score = 7;
    }

    switch (score)
    {
        case 1:
            cout << "Level: 10" << endl;
            cout << "Awesome \\OoO/" << endl;
            break;
        case 2:
            cout << "Level: 9" << endl;
            cout << "Great \\^o^/" << endl;
            break;
        case 3:
            cout << "Level: 8" << endl;
            cout << "Good ^o^" << endl;
            break;
        case 4:
            cout << "Level: 7" << endl;
            cout << "Not bad ^_^" << endl;
            break;
        case 5:
            cout << "Level: 6" << endl;
            cout << "Do your best *o*" << endl;
            break;
        case 6:
            cout << "Level: 5" << endl;
            cout << "Never give up *_*" << endl;
            break;
        case 7:
            cout << "Level: <5" << endl;
            cout << "God bless you...Orz" << endl;
            break;
    }













    return 0;
}
