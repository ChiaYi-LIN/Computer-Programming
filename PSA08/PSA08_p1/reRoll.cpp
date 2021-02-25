//
//  reRoll.cpp
//  PSA08_p1
//



#include "reRoll.hpp"

// this function is called at second, third, forth.... turn
int reRoll(int firstPoint, int point) {

    extern int dice();
    int reroll = dice();
    cout << "Player point: " << reroll << endl;
    if ((reroll+point)>50||reroll==7)
    {
        cout << "Player Loss" << endl;
        return 0;
    }
    else if (reroll==firstPoint)
    {
        cout << "Player Win" << endl;
        return -1;
    }
    else
    {
        return reroll;
    }

    // TODO
    // if the cummulative points larger than 50 or the points of two dice equal to 7, player loses
    // if the points of two dice equal to the points of first turn, player wins
    // otherwise, continue
    // Hint: you could use a local static variable to record the cummulative sum of points of each turn

}



