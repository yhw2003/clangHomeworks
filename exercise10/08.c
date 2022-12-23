_Bool func(int const * input, int len, int high)
{
  for (int i = 0; i < len/2; ++i)
  {
    for (int j = 0; j < high; ++j)
    {
      if(input[j * len + high] != input[i * len + j])
      {
        return 0;
      }
    }
  }
  return 1;
}