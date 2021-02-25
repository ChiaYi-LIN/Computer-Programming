#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char wFace[], const char wSuit[]);

struct PokerData
{
    const char suit[4] = {'s', 'h', 'd', 'c'};
    const char face[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    int deck[4][13];
}A;

int main()
{

    srand(time(0));
    shuffle(A.deck);
    deal(A.deck, A.face, A.suit);

    return 0;
}

void shuffle(int wDeck[][13])
{
    int row, column, card;
    for(card=1; card<=52; card++)
    {
        do{
            row = rand()%4;
            column = rand()%13;
        }while(wDeck[row][column]!=0);
        wDeck[row][column] = card;
    }
}

void deal(const int wDeck[][13], const char wFace[], const char wSuit[])
{
    for(int i=0; i<4; i++)
    {
        cout<<"Cards for Player "<<i+1<<":"<<endl;
        for(int j=0; j<13; j++)
        {
            int num = wDeck[i][j]-1;
            int csuit = num/13;
            int cface = num%13;
            cout<<wFace[cface]<<wSuit[csuit]<<"   ";
        }
        cout<<endl<<endl;
    }
}
