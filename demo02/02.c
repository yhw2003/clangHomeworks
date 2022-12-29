#include<stdio.h>

int main()
{
  char str[200];
  int n, m, i, j = 0;
  int temp = 0, flag = 0;
  scanf("%d%d", & n, & m);
  for (i = 0; i < n; i++)
  {
    str[i] = i + 1;
  }
  while (1)
  {
    j++;
    if (j > n)
      j -= n;
    if (str[j - 1] == 0)
    {
      continue;
    }
    temp++;
    if (temp == m && str[j - 1] != 0)
    {
      str[j - 1] = 0;
      printf("%d ", j);
      temp = 0;
      flag++;
    }
    if (flag == n)
      break;
  }
  return 0;
}