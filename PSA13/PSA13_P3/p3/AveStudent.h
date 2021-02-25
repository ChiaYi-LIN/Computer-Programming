#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class AveStudent : public Student{
 public:
  	//[TODO]
  	AveStudent(string, int);
  	~AveStudent();
  	void setAveScore(int);
  	double getAveScore();
  	void print() const;
 private:
    //[TODO]
    double totalStudent;
    double totalScore;
    double aveScore;
};
