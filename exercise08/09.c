//求最大公约数
#include <stdio.h>

int main()
{
  //input two numbers
  int a,b;
  printf("please input two numbers:");
  scanf("%d%d",&a,&b);
  if (a<b)
  {
    int temp=a;
    a=b;
    b=temp;
  }
  if (a == b)
  {
    printf("the greatest common divisor is %d\n",a);
    return 0;
  }
  else
  {
    int c=a%b;
    while (c!=0)
    {
      a=b;
      b=c;
      c=a%b;
    }
    printf("the greatest common divisor is %d\n",b);
  }
}