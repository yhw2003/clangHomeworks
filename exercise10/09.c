#include <stdio.h>

#define N 5

//MxN矩阵输入
int input(int a[][N], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  return 0;
}

//输出
int output(int a[][N], int m, int n)
{
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}

//求和

int sum(int a[][N], int m, int n)
{
  int sum = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum += a[i][j];
    }
  }
  return sum;
}