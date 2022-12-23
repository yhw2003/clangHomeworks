#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//模拟一万次骰子，输出6出现的几率
int research()
{
  int i, k, count = 0;
  srand(time(NULL));
  for (i = 0; i < 10000; i++)
  {
    k = rand() % 6 + 1;
    if (k == 6)
      count++;
  }
  return count;
}