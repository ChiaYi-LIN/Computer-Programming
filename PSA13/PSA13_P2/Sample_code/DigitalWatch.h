class DigitalWatch
{
    friend ostream& operator<<(ostream &, const DigitalWatch &);
    public:
        DigitalWatch();
        bool setTime(int h, int m, int s);
        void update(int s);
        void display(bool twelve);
        DigitalWatch operator+ (const DigitalWatch &);
    private:
        int hour, minute, second;
};

ostream& operator<<(ostream &, const DigitalWatch &);
//display() => show the time of the
//             watch in either 12-hour clock or
//             24-hour clock convention. Note that hour,
//             minute and second are shown as 2-digit format.

//setTime() => provides an interface for setting the
//             time of the watch. If the setting is illegal, the
//             function should not change the time and return false.

//update() => can correctly add an elapsed
//            number of seconds (input by user)
//            to update the time of the watch.
