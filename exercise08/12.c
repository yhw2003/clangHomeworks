#include <stdio.h>

extern int fYn(int n);

int main()
{
  for (int i = 0; i < 4 ; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d\t\t",fYn(i*4+j));
    }
    printf("\n");
  }
}

int fYn(int n)
{
  if (0 < n && n < 3)
  {
    return n;
  }
  if (n >= 3)
  {
    return fYn(n - 1) + fYn(n - 2) + fYn(n - 3);
  }
  return -1;
}