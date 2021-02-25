#include <iostream>
#include <cmath>
class Cylinder{
private:
    double radius;
    double height;
    const double PI = 3.14159;
	//[TODO]
public:
    Cylinder();
    ~Cylinder();
    bool nonnegative(double, double);
    void setCylinder(double, double);
    int get_count();
    double getRadius();
    double getHeight();
    double area();
    double volume();
	//[TODO]
};

