#include <stdio.h>

extern int reserve(int num);

int main()
{
  int n;
  printf("Enter a number: \n");
  scanf("%d", &n);
  if (n == reserve(n))
  {
    printf("The number is a palindrome \n");
  }
  else
  {
    printf("The number is not a palindrome \n");
  }
}

int reserve(int num)
{
  int reserveNum = 0;
  while (num)
  {
    reserveNum = reserveNum * 10 + num % 10;
    num /= 10;
  }
  return reserveNum;
}