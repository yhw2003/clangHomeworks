#include <stdio.h>

extern void move(char a, char b);
extern void Hanoi(int n, char a, char b, char c);

int main()
{
  int n;
  printf("Please input the number of disks:");
  scanf("%d", &n);
  Hanoi(n, 'A', 'B', 'C');
  return 0;
}

void move(char a, char b)
{
  printf("%c-->%c\n", a, b);
}

void Hanoi(int n, char a, char b, char c)
{
  if (n == 1)
    move(a, c);
  else
  {
    Hanoi(n - 1, a, c, b);
    move(a, c);
    Hanoi(n - 1, b, a, c);
  }
}