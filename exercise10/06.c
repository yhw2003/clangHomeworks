int sum(int input[][4])
{
  int _sum = 0;
  for (int i = 0; i < 4; ++i)
  {
    _sum = input[i][i];
  }
  return _sum;
}

int pSum(int input[][4])
{
  int _sum = 0;
  for (int i = 0; i < 4; ++i)
  {
    _sum = input[3-i][i];
  }
  return _sum;
}

