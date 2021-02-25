#include <stdio.h>
#include <iostream>

using namespace std;

int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

int countWays(int s)
{
    return fib(s + 1);
}

int main ()
{

  printf("Input the steps of the staircase: ");
  int staircase = 0;
  cin >> staircase;
  printf("Number of ways = %d", countWays(staircase));
  return 0;
}


