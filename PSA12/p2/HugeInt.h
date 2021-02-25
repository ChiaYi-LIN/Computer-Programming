#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class HugeInt
{
    friend ostream& operator<<(ostream &, const HugeInt &);
    public:
        HugeInt operator+ (const HugeInt&);
        HugeInt& operator+= (const HugeInt&);
        HugeInt(string);
        HugeInt();
        ~HugeInt();
        char theNumber[31];
};

ostream& operator<<(ostream &, const HugeInt &);

