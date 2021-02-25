#include "Point2D.h"

int main() {
    Point2D p1(5, 5);
    Point2D p2(10, 10);
    Point2D p3;

    cout << "p3(x, y) = ("
         << p3
         << ")" << endl;

    p3 = p1 + p2;
    cout << "p3(x, y) = ("
         << p3
         << ")" << endl;

    p3 = p2 - p1;
    cout << "p3(x, y) = ("
         << p3
         << ")" << endl;

    p3 = ++p1;
    cout << "p3(x, y) = ("
         << p3
         << ")" << endl;

    return 0;
}
