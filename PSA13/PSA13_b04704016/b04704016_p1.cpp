#include <iostream>
#include <string>
using namespace std;

class Point{
public:
    Point(int a=0, int b=0){x=a; y=b;}
    int x, y;
};
class Figure{
public:
	Figure(){ next = 0; }
	virtual float area(){ return 0; }
	void link(Figure *pFigure){ next = pFigure; }
	Figure *getLink(){ return next; }
protected:
    Figure *next;
};
class LineSegment : public Point, public Figure{
public:
    LineSegment(int x1=0, int y1=0, int x2=0, int y2=0) : Figure(){
        //set point
        p1.x=x1;
        p1.y=y1;
        p2.x=x2;
        p2.y=y2;
    }
    float area(){return 0;}
protected:
    Point p1, p2;
};

class Rectangle : public Point, public Figure{
public:
    Rectangle(int x1=0, int y1=0, int x2=0, int y2=0): Figure(){
        //set point
        topLeft.x=x1;
        topLeft.y=y1;
        bottomRight.x=x2;
        bottomRight.y=y2;
    }
    float area(){
        return (bottomRight.x-topLeft.x)*(bottomRight.y-topLeft.y);
    }
protected:
    Point topLeft, bottomRight;
};

class Ellipse : public Point, public Figure{
public:
    Ellipse(int x1=0, int y1=0, int x2=0, int y2=0):PI(3.14159), Figure(){
        //set point
        center.x=x1;
        center.y=y1;
        axis.x=x2;
        axis.y=y2;
    }

    float area(){
        return PI*(axis.x-center.x)*(axis.y-center.y);
    }
protected:
    Point center, axis;
    const float PI;
};
int main()//don't modify main()
{
    int i=0;
    string nameFigure[3]={"Line", "Rectangle", "Ellipse"};
    LineSegment line(1,1, 10, 10);
    Rectangle   rect(10, 10, 90, 50);
    Ellipse     ellipse(30, 30, 40, 40);
    Figure     *pBase;

    rect.link( &ellipse );
    line.link( &rect );
    pBase = &line;

    while( pBase )
    {
        cout <<nameFigure[i]<< " area = " << pBase->area() << endl;
        pBase = pBase->getLink();
        i++;
    }
}
