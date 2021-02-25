#include "Student.h"

using namespace std;

//[TODO]
Student::Student(string s, int i)
{
    name = s;
    score = i;
}

Student::~Student(){}

void Student::setScore(int a)
{
    score = a;
}

void Student::setName(string a)
{
    name = a;
}

int Student::getScore()
{
    return score;
}

string Student::getName()
{
    return name;
}
// print
void Student::print() const{
 cout << "Name >> " << name << endl;
 cout << "Score >> " << score << endl;
}
