#include "HugeInt.h"
int main() {
    HugeInt n1("99999999999999999999999999999");
    HugeInt n2("1");
    HugeInt n3;

    cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << endl;

    n3 = n1 + n2;
    cout << n1 << " + " << n2 << "\n= " << n3 << endl;

    n3 += n2;
    cout << "n3 is " << n3 << endl;

    return 0;
}
