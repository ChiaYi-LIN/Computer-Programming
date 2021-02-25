#include <iostream>
using namespace std;
int main() {
    //You can't use "cout<< a or b" directly
    float a=3.15, b=5.5;//don't move
    float *ptr1, *ptr2;
    ptr1 = &a;
    ptr2 = &b;
    cout<<"a="<< *ptr1<<endl;
    cout<<"b="<< *ptr2<<endl;
    cout<<"axb="<< (*ptr1) * (*ptr2) <<endl;
	return 0;
}
