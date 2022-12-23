#define IS_ODD(X) (X)%2==0
#include <stdio.h>

int main()
{
  int cnt_ODD = 0;
  int cnt_EVEN = 0;
  int x;
  printf("Enter numbers: ");
  while (1)
  {
    scanf("%d", &x);
    if(IS_ODD(x))
      cnt_EVEN++;
    else
      cnt_ODD++;
    
    if (getchar() == '\n')
      break;
  }
  printf("\nODD: %d\nEVENS: %d\n", cnt_ODD, cnt_EVEN);
  return 0;
}