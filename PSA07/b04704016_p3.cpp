#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

double cir_area(double);
double tri_area(double);

int main()
{
    double face_r = 0, eye_r = 0, mouth_x = 0;
    double face_a = 0, eye_a = 0, mouth_a = 0;
    double BLUE_AREA = 0;

    cin >> face_r >> eye_r >> mouth_x;

    face_a = cir_area(face_r);
    eye_a = cir_area(eye_r);
    mouth_a = tri_area(mouth_x);

    while (face_a<=(2*eye_a+mouth_a))
    {
        cout << "Are you sure it's a face!?\nPlease input again!" << endl;
        cin >> face_r >> eye_r >> mouth_x;

        face_a = cir_area(face_r);
        eye_a = cir_area(eye_r);
        mouth_a = tri_area(mouth_x);
    }

    BLUE_AREA = face_a - 2*eye_a - mouth_a;

    cout << fixed << setprecision(2) << BLUE_AREA << endl;

    return 0;
}

double cir_area(double r)
{
    return (r*r*3.14);
}

double tri_area(double x)
{
    return (sqrt(3) * pow(x,2) / 4);
}


