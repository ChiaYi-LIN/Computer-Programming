#include <iostream>

using namespace std;

class Point2D
{
    friend ostream& operator<<(ostream &, const Point2D &);
    private:

        int x,y;
    public:
        Point2D operator+ (const Point2D&);
        Point2D operator- (const Point2D&);
        Point2D& operator++ ();
        Point2D(int, int);
        Point2D();
        ~Point2D();
};

ostream& operator<<(ostream &, const Point2D &);

