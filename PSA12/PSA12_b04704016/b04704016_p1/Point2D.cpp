#include "Point2D.h"


ostream &operator<<(ostream &output, const Point2D &r)
{
    output << r.x << "," << r.y;
    return output;
}


Point2D::Point2D()
{
    x = 0;
    y = 0;
}

Point2D::Point2D(int theX, int theY)
{
    x = theX;
    y = theY;
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

Point2D Point2D::operator+ (const Point2D& add)
{
    Point2D num3;
    num3.x = x + add.x;
    num3.y = y + add.y;
    return num3;
}

Point2D Point2D::operator- (const Point2D& theMinus)
{
    Point2D num3;
    num3.x = x - theMinus.x;
    num3.y = y - theMinus.y;
    return num3;
}

Point2D& Point2D::operator++ ()
{
    ++x;
    ++y;
    return *this;
}
