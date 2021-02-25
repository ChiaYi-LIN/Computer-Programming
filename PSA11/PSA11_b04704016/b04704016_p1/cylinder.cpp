#include "cylinder.h"

extern double radius;
extern double height;
extern const double PI;
static int count = 0;

Cylinder::Cylinder()
{
    radius = 0;
    height = 0;
}

Cylinder::~Cylinder()
{

}

bool Cylinder::nonnegative(double r, double h)
{
    bool nonnegative = true;
    if(r < 0 || h < 0)
    {
        nonnegative = false;
    }
    return nonnegative;
}

void Cylinder::setCylinder(double r, double h)
{
    radius = r;
    height = h;

}

int Cylinder::get_count()
{
    return count;
}

double Cylinder::getRadius()
{
    return radius;
}

double Cylinder::getHeight()
{
    return height;
}

double Cylinder::area()
{
    return 2 * radius * radius * PI + 2 * radius * PI * height;
}

double Cylinder::volume()
{
    count += 1;
    return radius * radius * PI * height;

}
//[TODO]




