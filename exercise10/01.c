int Fib(int num)
{
  int fib[num + 1];
  for (int i = 0; i < num; i++)
  {
    fib[num] = 1;
  }
  for (int i = 2; i < num; i++)
  {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib[num];
}