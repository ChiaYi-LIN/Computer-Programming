#include <iostream>
#include <iomanip>
#include "AveStudent.h"

using namespace std;

int main(){

	AveStudent first("Heron", 75);
	cout << "====Highest score====" <<endl;
	cout << "Name >> " << first.getName() << endl;
	cout << "Score >> " << first.getScore() << endl;
	cout << "AveScore >> " << first.getAveScore() << endl;
	cout << "=====================" <<endl;
	string name;
	int score;
	while(first.getAveScore()>70){
		cout << "New name >> ";
		cin >> name;
		cout << name <<"'s score >> ";
		cin >> score;
		cout << "====Update  score====" <<endl;
		if(score>=first.getScore()){
			first.setName(name);
			first.setScore(score);
		}
		first.setAveScore(score);
		first.print();
		cout << "=====================" <<endl;
	}
	cout << "====Highest score====" <<endl;
	first.print();
	cout << "=====================" <<endl;

 return 0;
}


//class Student =>setName(),setScore(),getName(),getScore(),print()
//class AveStudent =>setAveScore(),getAveScore(),print()

