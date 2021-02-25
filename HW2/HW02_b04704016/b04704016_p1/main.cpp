#include "sortlib.h"

int main()
{
    start:
    int inputNumber;
    cin >> inputNumber;
    if(inputNumber==0)
    {
        return 0;
    }
    while(inputNumber > 99999 || inputNumber < 0)
    {
        cin >> inputNumber;
        if(inputNumber==0)
        {
            return 0;
        }
    }
    if(output(reverseSortNumber(inputNumber),sortNumber(inputNumber)) == -1)
    {
        goto start;
    }

    return 0;
}
