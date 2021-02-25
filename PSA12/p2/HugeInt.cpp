#include "HugeInt.h"
ostream &operator<<(ostream &output, const HugeInt &r)
{
    int i;
    for(i=0; i<30; i++)
    {
        if(r.theNumber[i] >= 48 && r.theNumber[i] <= 57)
        {
            output << r.theNumber[i];
        }
    }
    return output;
}

HugeInt::HugeInt()
{
    int i;
    for(i=0; i<30; i++)
    {
        theNumber[i] = 0;
    }
    theNumber[29] = '0';
}

HugeInt::HugeInt(string s)
{
    int i;
    for(i=29; i>=0; i--)
    {
        if((s.length()-1-(29-i)) >= 0 )
        {
            if(s[s.length()-1-(29-i)] >= 48 && s[s.length()-1-(29-i)] <= 57)
            {
                theNumber[i] = s[s.length()-1-(29-i)];
            }
            else
            {
                theNumber[i] = 0;
            }
        }
        else
        {
            theNumber[i] = 0;
        }
    }
    for(i=(29-s.length()); i>=0; i--)
    {
        theNumber[i] = 0;
    }
}

HugeInt::~HugeInt()
{
    int i;
    for(i=0; i<30; i++)
    {
        theNumber[i] = 0;
    }
    theNumber[29] = '0';
}

HugeInt HugeInt::operator+ (const HugeInt& add)
{
    int i;
    HugeInt output;
    output.theNumber[29] = 0;
    for(i=29; i>=0; i--)
    {
        if(output.theNumber[i] != 49)
        {
            if(theNumber[i]+add.theNumber[i] >= 106)
            {
                output.theNumber[i] = theNumber[i]+add.theNumber[i]-58;
                output.theNumber[i-1] = 49;
            }
            else if(theNumber[i]+add.theNumber[i] >= 96)
            {
                output.theNumber[i] = theNumber[i]+add.theNumber[i]-48;
            }
            else if(theNumber[i]+add.theNumber[i] >= 48)
            {
                output.theNumber[i] = theNumber[i]+add.theNumber[i];
            }
            else
            {
                output.theNumber[i] = 0;
            }
        }
        else
        {
            if(theNumber[i]+add.theNumber[i] >= 106)
            {
                output.theNumber[i] = theNumber[i]+add.theNumber[i]-58+1;
                output.theNumber[i-1] = 49;
            }
            else if(theNumber[i]+add.theNumber[i] >= 96)
            {
                if(theNumber[i]+add.theNumber[i] == 105)
                {
                    output.theNumber[i] = 48;
                    output.theNumber[i-1] = 49;
                }
                else
                {
                    output.theNumber[i] = theNumber[i]+add.theNumber[i]-48+1;
                }
            }
            else if(theNumber[i]+add.theNumber[i] >= 48)
            {
                if(theNumber[i]+add.theNumber[i]==57)
                {
                    output.theNumber[i] = 48;
                    output.theNumber[i-1] = 49;
                }
                else
                {
                    output.theNumber[i] = theNumber[i]+add.theNumber[i]+1;
                }
            }
            else
            {
                output.theNumber[i] = 49;
            }
        }
    }

    return output;
}

HugeInt& HugeInt::operator+= (const HugeInt& rhs)
{
    int i;
    for(i=29; i>=0; i--)
    {
        if(this->theNumber[i] == 58)
        {
            this->theNumber[i] = 48;
            if(this->theNumber[i-1] != 0)
            {
                this->theNumber[i-1] += 1;
            }
            else if(this->theNumber[i-1] == 0)
            {
                this->theNumber[i-1] = 49;
            }
        }
        this->theNumber[i] += rhs.theNumber[i];

        if(this->theNumber[i] >= 106)
        {
            this->theNumber[i] -= 58;
            if(this->theNumber[i-1] != 0)
            {
                this->theNumber[i-1] += 1;
            }
            else if(this->theNumber[i-1] == 0)
            {
                this->theNumber[i-1] = 49;
            }
        }
        else if(this->theNumber[i] >= 96)
        {
            this->theNumber[i] -= 48;
        }
        else if(this->theNumber[i] >= 48)
        {
            this->theNumber[i];
        }
        else
        {
            this->theNumber[i] = 0;
        }

    }
    return *this;
}

