#include <stdlib.h>
#include <stdio.h>

extern _Bool isPrime(int num);


int main()
{
  int num;
  scanf("%d", &num);
  for (int i = 1; i <= num; i++)
  {
    if (isPrime(i))
    {
      for (int j = 1; j <= num; j++)
      {
        if (isPrime(j))
        {
          if (i + j == num)
          {
            printf("%d = %d + %d", num, i, j);
            return 0;
          }
        }
      }
    }
  }
}

_Bool isPrime(int num)
{
  if(num <= 1)
  {
    return 0;
  }
  if (num <= 3)
  {
    return 1;
  }
  
  static int lastNum = -1;
  static int lastStep;
  static _Bool * _isPrime = NULL;
  if (lastNum < num)
  {
    lastNum = num * 2 ;
    free(_isPrime);
    _isPrime = malloc(lastNum * sizeof(_Bool));
    lastStep = 2;
    for (int i = 0; i <lastNum; ++i)
    {
      _isPrime[i] = 1;
    }
    
    num++;
    for (int i = lastStep; i < lastNum; ++i)
    {
      if(_isPrime[i])
      {
        for (int j = 2; j*i <= lastNum; ++j)
        {
          _isPrime[i*j] = 0;
        }
      }
    }
    num--;
    lastStep = lastNum;
  }
  return _isPrime[num];
}
