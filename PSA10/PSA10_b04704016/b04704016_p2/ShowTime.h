//#ifdef SHOWTIME_H
//#define SHOWTIME_H


class ShowTime
{
    private:
        int hour;
        int minute;
        char time[5];
    public:
        ShowTime(int h,int m);
        void setTime(int h, int m);
        bool loadMedia();
};

//#endif
