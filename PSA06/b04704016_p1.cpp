#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

  // aPtr will reference the first element of array a
  int *aPtr, N;
  int last;

  // N is the size of array a
  cout << "Please enter array size : ";
  cin >> N;

  // initial an array with size N
  int a[N] = {0};

  // put value in array a
  for (int i=0; i<N; i++){
    a[i] = i;
  }

  // use pointer aPtr to get the first element of array a
  aPtr = &a[0];
  cout << "The address of aPtr is: " << &aPtr << endl;

  // because sizeof(int) = 4;
  // we want to print the second element of array
  // the address of second element is aPtr + 4
  // use * to dereference the value
  cout << "The second element is: " << *(aPtr+1) <<endl;


  // assign the last element to int number
  last = a[N-1];
  cout << "The last is: " << last << endl;

  // print the "value" of entire array
  cout<<"The values of array:  ";
  for (int i=0; i<N; i++) {
    cout << (*aPtr+i) << " ";
  }

  return 0;
}
