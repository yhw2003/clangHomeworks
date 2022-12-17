//判断一个数字是否是完全数
#include <stdio.h>
#include <stdlib.h>

_Bool isPerfectNumber(int n)
{
  int sum = 0;
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      sum += i;
    }
  }
  return sum == n;
}

//判断1000以内的所有数字是否是完全数，malloc地址用于储存，返回指针

int *getPerfectNumbers(int *count)
{
  int *p = (int *) malloc(sizeof(int) * 1000);
  for (int i = 0; i < 1000; i++)
  {
    p[i] = 0;
  }
  int index = 0;
  for (int i = 1; i < 1000; i++)
  {
    if (isPerfectNumber(i))
    {
      p[index] = i;
      index++;
    }
  }
  *count = index;
  return p;
}

//测试
int main()
{
  int cnt = 0;
  int *p = getPerfectNumbers(&cnt);
  for (int i = 0; i < cnt; i++)
  {
    printf("%d ", p[i]);
  }
  return 0;
}