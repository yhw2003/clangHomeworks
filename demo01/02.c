//加法回文
#include <stdio.h>

int main()
{
  // 10(a+c) + (b+d) = 10(b+d) + (a+c) => a+c = b+d
  // a&c in [1, 9], b&d in [0, 9]
  for (int k = 0; k < 9; ++k)
  {
    for (int n1 = 1; n1 + k < 10; ++n1)
    {
      for (int n2 = 1; n2 + k < 10; ++n2)
      {
        printf("%d%d+%d%d\n", n1 + k, n1, n2, n2 + k);
      }
    }
  }
  return 0;
}