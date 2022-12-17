//使用递归的方式计算n的阶乘

int factorial_A(int n)
{
  if (n == 1)
  {
    return 1;
  } else
  {
    return n * factorial_A(n - 1);
  }
}

//使用循环的方式计算n的阶乘

int factorial_B(int n)
{
  int result = 1;
  for (int i = 1; i <= n; i++)
  {
    result *= i;
  }
  return result;
}