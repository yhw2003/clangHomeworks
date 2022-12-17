//寻找无暇素数
//这个质数算法属实不容易

#include <stdlib.h>
#include <stdio.h>
#define _TARGET 999

extern _Bool isPrime(int num);
extern int reserve(int num);

int main()
{
//  isPrime(20);
  for(int i = 100; i <= _TARGET; i++)
  {
    if(isPrime(i) && isPrime(reserve(i)))
    {
      printf("%d ", i);
    }
  }
  printf("\n");
}

//判断是否为素数
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


//获得逆序数
int reserve(int num)
{
    int reserveNum = 0;
    while (num)
    {
        reserveNum = reserveNum * 10 + num % 10;
        num /= 10;
    }
    return reserveNum;
}