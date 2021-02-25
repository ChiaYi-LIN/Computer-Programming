#include "AveStudent.h"

using namespace std;

//[TODO]
AveStudent::AveStudent(string s, int i):Student(s, i)
{
    totalStudent = 1;
    totalScore = i;
    aveScore = totalScore / totalStudent;
}

AveStudent::~AveStudent(){}

void AveStudent::print() const{
    //[TODO]
    Student::print();
    cout << "AveScore >> " << aveScore << endl;
}

void AveStudent::setAveScore(int a)
{
    totalScore += a;
    totalStudent += 1;
    aveScore = totalScore / totalStudent;
}

double AveStudent::getAveScore()
{
    return aveScore;
}
