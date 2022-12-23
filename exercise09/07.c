#include <stdio.h>

double myPow(double x, int n)
{
  if(n == 0)
  {
    return 1;
  } else
  {
    return x * myPow(x, n-1);
  }
}