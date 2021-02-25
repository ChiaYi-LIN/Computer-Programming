//time.h

#ifndef TIME_H
#define TIME_H

class Time
{
public:
    Time();
    void printStandard();
    void printUniversal();
    void setTime(int, int, int);
private:
    int hour;
    int minute;
    int second;
};

#endif
