#include <stdio.h>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
void tumbleNorth();
void tumbleEast();
void tumbleWest();
void tumbleSouth();
void output();

int top = 1;
int north = 2;
int west = 3;
int down = 6;
int south = 5;
int east = 4;

int main ()
{
    int flag = 0;
    string inputString;
    getline(cin, inputString);
    char *theString = new char[inputString.length()+1];
    theString[inputString.length()] = '\0';
    for(int i = 0; i < inputString.length(); i++)
    {
        theString[i] = inputString[i];
    }

    char* tokenString;
    tokenString = strtok(theString," ");
    while(tokenString != NULL)
    {
        if(*tokenString == 'e' && *(tokenString+1) == 'a' && *(tokenString+2) == 's' && *(tokenString+3) == 't' && *(tokenString+4) == '\0')
        {
            flag = 1;
        }
        else if(*tokenString == 'w' && *(tokenString+1) == 'e' && *(tokenString+2) == 's' && *(tokenString+3) == 't' && *(tokenString+4) == '\0')
        {
            flag = 2;
        }
        else if(*tokenString == 's' && *(tokenString+1) == 'o' && *(tokenString+2) == 'u' && *(tokenString+3) == 't' && *(tokenString+4) == 'h' && *(tokenString+5) == '\0')
        {
            flag = 3;
        }
        else if(*tokenString == 'n' && *(tokenString+1) == 'o' && *(tokenString+2) == 'r' && *(tokenString+3) == 't' && *(tokenString+4) == 'h' && *(tokenString+5) == '\0')
        {
            flag = 4;
        }

        switch(flag)
        {
            case 1:
                tumbleEast();
                break;
            case 2:
                tumbleWest();
                break;
            case 3:
                tumbleSouth();
                break;
            case 4:
                tumbleNorth();
                break;
            default:
                break;
        }
        flag = 0;
        tokenString = strtok(NULL," ");
    }

    output();

    delete [] theString;
    return 0;
}

void tumbleNorth()
{
    int temporNorth = 0;
    int temporTop = 0;
    temporNorth = top;
    temporTop = south;
    north = temporNorth;
    top = temporTop;
    south = 7 - north;
    down = 7 - top;
}

void tumbleEast()
{
    int temporEast = 0;
    int temporTop = 0;
    temporEast = top;
    temporTop = west;
    east = temporEast;
    top = temporTop;
    west = 7 - east;
    down = 7 - top;
}

void tumbleWest()
{
    int temporWest = 0;
    int temporTop = 0;
    temporWest = top;
    temporTop = east;
    west = temporWest;
    top = temporTop;
    east = 7 - west;
    down = 7 - top;
}

void tumbleSouth()
{
    int temporSouth = 0;
    int temporTop = 0;
    temporSouth = top;
    temporTop = north;
    south = temporSouth;
    top = temporTop;
    north = 7 - south;
    down = 7 - top;
}

void output()
{
    cout << "The number on the top face when the game finished: " << top << endl;
}


