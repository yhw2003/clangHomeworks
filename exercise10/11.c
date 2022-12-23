//select_sort

int select_sort(int *a, int n)
{
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }
  return 0;
}