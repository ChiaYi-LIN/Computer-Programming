#include <iostream>

using namespace std;

int main()
{
    int age;
    float height;
    float weight;
    cout << "How old are you?" << endl;
    cin >> age;
    cout << endl;
    cout << "What's your weight?" << endl;
    cin >> weight;
    cout << endl;
    cout << "How tall are you?" << endl;
    cin >> height;
    cout << endl;
    cout << "So, you are " << age << " years old" << endl;
    cout << "and your weight is " << weight << " kg" << endl;
    cout << "and your height is " << height << " cm" << endl;

    return 0;
}
