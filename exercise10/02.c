/*
2x3行列式翻转
[a,b,c]      [a,d]
         ==> [b,e]
[d,e,f]      [c,f]
*/
#include <stdio.h>

void func(int * input)
{
  int buf = input[1];
  input[1] = input[3];
  input[3] = input[4];
  input[4] = input[2];
  input[2] = buf;
}

int main()
{
  int i[2][3] = {{1,2,3},{4,5,6}};
  func(i);
  int * j = (int *)i;
  for (int k = 0; k < 3; k++)
  {
    for (int l = 0; l < 2; l++)
    {
      printf("%d ", j[k*2+l]);
    }
    printf("\n");
  }
}