#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    char sentence[101] = {};
    char check_upper[27] = {};
    char check_lower[27] = {};
    int count_num[27] = {};
    int differ = 0;
    int i = 0, j = 0;

    cin >> sentence;

    for(i=0; i<26; i++)
    {
        check_upper[i] = 65 + i;
    }

    for(i=0; i<26; i++)
    {
        check_lower[i] = 97 + i;
    }

    for (i=0; i<101; i++)
    {
        for (j=0; j<26; j++)
        {
            if (sentence[i]==check_upper[j]||sentence[i]==check_lower[j])
            {
                count_num[j] += 1;
            }
        }
    }

    for (i=0; i<26; i++)
    {
        while (count_num[i]<=0&&i<26)
        {
            i += 1;
        }
        if (i<26)
        {
        cout << check_upper[i] << "'s count = " << count_num[i] << "\t";
        }
        i += 1;
        while (count_num[i]<=0&&i<26)
        {
            i += 1;
        }
        if (i<26)
        {
        cout << check_upper[i] << "'s count = " << count_num[i] << "\t";
        }
        i += 1;
        while (count_num[i]<=0&&i<26)
        {
            i += 1;
        }
        if (i<26)
        {
        cout << check_upper[i] << "'s count = " << count_num[i] << "\t";
        }
        cout << endl;

    }

    for (i=0; i<26; i++)
    {
        if (count_num[i]>0)
        {
            differ +=1;
        }
    }

    cout << "\nThere are " << differ << " different alphabets in your input." << endl;

    return 0;
}
