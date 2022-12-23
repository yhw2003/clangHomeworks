int binary_search(int key, int *a, int n)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (key < a[mid])
      high = mid - 1;
    else if (key > a[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}