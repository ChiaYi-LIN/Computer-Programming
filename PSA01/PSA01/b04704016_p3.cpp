#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    cout << "size of int8_t   = " << sizeof(int8_t) << " bytes" << endl;
    cout << "size of int16_t  = " << sizeof(int16_t) << " bytes" << endl;
    cout << "size of uint8_t  = " << sizeof(uint8_t) << " bytes" << endl;
    cout << "size of uint16_t = " << sizeof(uint16_t) << " bytes" << endl;
    cout << endl;

    cout << "int_8: " << -128 << " ~ " << 127 << endl;
    printf("int_16: %d ~ %d\n", -256*256/2, 256*256/2-1);
    cout << "uint_8: " << 0 << " ~ " << 256-1 << endl;
    printf("uint_16: %d ~ %d\n", 0, 256*256-1);
    cout << endl;
}

