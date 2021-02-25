#include "sortlib.h"

int reverseSortNumber(int inputNumber)
{
    int currentNumber[5] = {0};
    int inputNumber_2 = inputNumber;
    int outputNumber = 0;
    int i = 0;
    //
    for(i = 4; i >= 0; i--)
    {
        currentNumber[i] = inputNumber_2 % 10;
        inputNumber_2 /= 10;
    }
    //
    sort(currentNumber,currentNumber+5);
    //
    if(inputNumber <= 9 && inputNumber >= 1)
    {
        reverse(currentNumber+4,currentNumber+5);
    }
    else if(inputNumber <= 99 && inputNumber >= 10)
    {
        reverse(currentNumber+3,currentNumber+5);
    }
    else if(inputNumber <= 999 && inputNumber >= 100)
    {
        reverse(currentNumber+2,currentNumber+5);
    }
    else if(inputNumber <= 9999 && inputNumber >= 1000)
    {
        reverse(currentNumber+1,currentNumber+5);
    }
    else if(inputNumber <= 99999 && inputNumber >= 10000)
    {
        reverse(currentNumber+0,currentNumber+5);
    }
    //
    for(i = 0; i < 5 ; i++)
    {
        outputNumber = 10000*currentNumber[0]+1000*currentNumber[1]+100*currentNumber[2]+10*currentNumber[3]+currentNumber[4];
    }
    //
    return outputNumber;
}

int sortNumber(int inputNumber)
{
    int currentNumber[5] = {0};
    int inputNumber_2 = inputNumber;
    int outputNumber = 0;
    int i = 0;
    //
    for(i = 4; i >= 0; i--)
    {
        currentNumber[i] = inputNumber_2 % 10;
        inputNumber_2 /= 10;
    }
    //
    sort(currentNumber,currentNumber+5);
    //
    for(i = 0; i < 5 ; i++)
    {
        outputNumber = 10000*currentNumber[0]+1000*currentNumber[1]+100*currentNumber[2]+10*currentNumber[3]+currentNumber[4];
    }
    //
    return outputNumber;

}

int output(int a, int b)
{
    static int round = 0;
    static int numberData[50] = {0};
    int outputNumber = 0;
    outputNumber = a - b;
    cout << outputNumber << endl;
    round +=1;
    numberData[round-1] = outputNumber;
    if(round >= 2)
    {
        for(int i = round-2; i >= 0; i--)
        {
            if(numberData[round-1] == numberData[i])
            {
                cout << round << endl;
                round = 0;
                return -1;
            }
        }
    }
    return output(reverseSortNumber(outputNumber),sortNumber(outputNumber));
}
