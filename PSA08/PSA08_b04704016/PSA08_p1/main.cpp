#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "initRoll.hpp"
#include "reRoll.hpp"

using namespace std;

int dice ();

int main() {

    // set the seed of rand()
    srand(time(0));

    int firstpoint;  // the points of first turn
    int status;      // the result of each turn (e.g. Win, Lose or Continue)
    int point = 0;		 // the points of second, third, ...., turn

    firstpoint = dice();
    point += firstpoint;
    if (initialRoll(firstpoint)==0) return 0;

    status = reRoll(firstpoint, point);
    while (status!=0&&status!=-1)
    {
        point += status;
        status = reRoll(firstpoint, point);
    }
    return 0;


    // TODO
    // use initialRoll() and reRoll() to complete problem 1
    // output the points each turn and the result of game

}



int dice (){
    int dice_1 = 0, dice_2 = 0;
    dice_1 = (rand()%6)+1;
    dice_2 = (rand()%6)+1;
    return dice_1+dice_2;
    // TODO
    // calculate the points of two dice
    // rolling a dice will appear 1 to 6 randomly
    // use rand()

}


