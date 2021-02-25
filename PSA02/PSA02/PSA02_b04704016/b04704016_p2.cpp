#include <iostream>

using namespace std;

int main()
{
    double x = 11.5;
    double Ans;
    Ans = x + 33 - 22;
    Ans = Ans * 11;
    Ans = Ans + 0.5;
    Ans = Ans * 8;
    Ans = ((int)Ans) % 10;
    cout << "The answer is: " << Ans << endl;

    return 0;
}
