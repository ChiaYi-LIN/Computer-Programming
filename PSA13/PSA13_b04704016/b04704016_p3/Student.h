#include <iostream>
#include <string>
using namespace std;

class Student{
 public:
     Student(string, int);
     ~Student();
     void print() const;
     void setScore(int);
     void setName(string);
     int getScore();
     string getName();
 	//[TODO]
 private:
     string name;
     int score;
  	//[TODO]
};
