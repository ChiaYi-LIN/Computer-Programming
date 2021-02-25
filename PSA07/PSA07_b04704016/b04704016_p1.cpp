#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

int output(int, int);

int main()
{
    int A = 0, i = 0, total = 0;
    cin >> A;
    for(i; total<=10*A; i++)
    {
    total = output(A, i);
    }
    cout << total << endl;

    return 0;
}

output(int A, int i)
{
    int answer = 0, j = 0;
    for (j; j<i; j++) answer += A + j;

    return answer;
}
