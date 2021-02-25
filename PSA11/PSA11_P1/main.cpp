#include "cylinder.h"
using namespace std;

int main(){

	Cylinder cyl;
	double r,h;
	while(1){
		cin >> r >> h;
		if(r*h==0){
			break;
		}else{
			if(cyl.nonnegative(r,h)){
				cyl.setCylinder(r,h);
				cout << "The cylinder"<<cyl.get_count()+1<< " is :" <<endl;
				cout << "Radius : " << cyl.getRadius() <<endl;
				cout << "Height : " << cyl.getHeight() <<endl;
				cout << "Surface area : " << cyl.area() <<endl;
				cout << "Volumn : " << cyl.volume() <<endl;
			}else{
				cout <<"Please input again!"<<endl;
			}
		}
	}
	cout << "Number of cylinders : "<<cyl.get_count()<<endl;

	//nonnegative()=>to check radius and height isn't negative
	//setCylinder()=>to set radius and height in private
	//get_count()=>to get the value of count
	//getRadius()=>to get radius in class
	//getHeight()=>to get height in class
	//area()=>to calculate the surface area of the cylinder
	//volume()=>to claculate the volume of the cylinder

	return 0;
}








