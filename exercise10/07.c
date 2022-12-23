void reserve(int a[], int size)
{
  for (int i = 0; i < size; ++i)
  {
    a[i] = a[size-i-1] + a[i];
    a[size-i-1] = a[i] - a[size-i-1];
    a[i] = a[i] - a[size-i-1];
  }
}