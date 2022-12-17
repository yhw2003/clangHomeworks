#include <stdio.h>

int main()
{
  double a, b;
  char op;
  char flag;
  do
  {
    //input
    printf("\n 输入运算式：\n");
    scanf("%lf%c%lf", &a, &op, &b);
    //计算 输出结果
    switch (op)
    {
      case '+':
        printf("%lf + %lf = %lf\n", a, b, a + b);
        break;
      case '-':
        printf("%lf - %lf = %lf\n", a, b, a - b);
        break;
      case '*':
        printf("%lf * %lf = %lf\n", a, b, a * b);
        break;
      case '/':
        if (b == 0)
        {
          printf("除数不能为0！\n");
        }
        else
        {
          printf("%lf / %lf = %lf\n", a, b, a / b);
        }
        break;
      default:
        printf("输入错误！\n");
        break;
    }
    printf("是否继续？(y/n)\n");
    scanf(" %c", &flag);
  } while (flag == 'y' || flag == 'Y');
  return 0;
}