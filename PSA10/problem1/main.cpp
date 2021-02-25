#include <iostream>
#include "time.h"

using namespace std;

int main() {
	Time t;
	// output Time object t's initial values
	cout << "The initial universal time is ";
	t.printUniversal();
	cout << "The initial standard time is ";
	t.printStandard();

	int hour, minute, second;
	cout << "Please input hour, minute and second: ";
	cin >> hour >> minute >> second;
	t.setTime(hour,minute,second); // change time

	//output Time object t's new values
	cout << "Universal time after setTime is ";
	t.printUniversal();
	cout << "Standard time after setTime is ";
	t.printStandard();

}