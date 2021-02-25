//
//  initRoll.cpp
//  PSA08_p1
//

#include "initRoll.hpp"

// this function is called only once (in first turn)
int initialRoll(int firstPoint) {

    cout << "Player point: " << firstPoint << endl;
    if (firstPoint==7||firstPoint==11)
    {
        cout << "Player Win" << endl;
        return 0;
    }
    else if((firstPoint==2||firstPoint==3)||firstPoint==12)
    {
        cout << "Player Loss" << endl;
        return 0;
    }
    else{return 1;}
    // TODO
    // if the total points of two dice equal to 7 or 11, player wins
    // if the total points of two dice equal to 2 or 3 or 12, player loses
    // otherwise, continue

}
