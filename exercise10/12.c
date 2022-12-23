int search(int *a, int size, int key)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (a[i] == key)
    {
      return i;
    }
  }
  return -1;
}