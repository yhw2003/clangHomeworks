//大数运算

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *num;
  int len;
} large_num, *large_num_ptr;

extern large_num_ptr create_large_num(int len);

extern void large_num_add(const large_num *const numA, const large_num *const numB, large_num_ptr *result);

extern large_num large_num_copy(const large_num *const num);

extern void large_num_minus(const large_num *const numA, const large_num *const numB, large_num_ptr result);

extern void large_num_print(const large_num *const num);

extern void large_num_input(large_num_ptr num);

int main()
{
  large_num_ptr numA = create_large_num(10), numB = create_large_num(10), result = create_large_num(10);
  large_num_input(numA);
  large_num_input(numB);
  large_num_add(numA, numB, result);
  large_num_print(result);
  return 0;
}


large_num_ptr create_large_num(int len)
{
  large_num_ptr p = (large_num_ptr) malloc(sizeof(large_num));
  p->num = (char *) malloc(sizeof(char) * len);
  p->len = len;
  return p;
}

//两个家数numA和numB相加，结果存放在result中，注意提前分配好result的空间
void large_num_add(const large_num *const numA, const large_num *const numB, large_num_ptr *result)
{
  int i, j, k, carry = 0;
  large_num_ptr numC = create_large_num(numA->len + 1);
  for (i = numA->len - 1, j = numB->len - 1, k = numC->len - 1; i >= 0 || j >= 0; i--, j--, k--)
  {
    int a = i >= 0 ? numA->num[i] - '0' : 0;
    int b = j >= 0 ? numB->num[j] - '0' : 0;
    int c = a + b + carry;
    numC->num[k] = c % 10 + '0';
    carry = c / 10;
  }
  numC->num[0] = carry + '0';
  free(*result);
  *result = numC;
}

//传入指针，返回全新的一个数
large_num large_num_copy(const large_num *const num)
{
  large_num new_num;
  for (int i = 0; i < num->len; i++)
  {
    new_num.num[i] = num->num[i];
  }
  new_num.len = num->len;
  return new_num;
}

//被减数numA，减数numB，结果result，注意提前分配result的空间
void large_num_minus(const large_num *const numA, const large_num *const numB, large_num_ptr result)
{
  int i, j, k, carry = 0;
  large_num_ptr numC = create_large_num(numA->len);
  for (i = numA->len - 1, j = numB->len - 1, k = numC->len - 1; i >= 0 || j >= 0; i--, j--, k--)
  {
    int a = i >= 0 ? numA->num[i] - '0' : 0;
    int b = j >= 0 ? numB->num[j] - '0' : 0;
    int c = a - b - carry;
    if (c < 0)
    {
      c += 10;
      carry = 1;
    } else
    {
      carry = 0;
    }
    numC->num[k] = c + '0';
  }
  free(result);
  result = numC;
}

void large_num_print(const large_num *const num)
{
  int i = 0;
  while (num->num[i] == '0')
  {
    i++;
  }
  for (; i < num->len; i++)
  {
    printf("%c", num->num[i]);
  }
  printf("\n");
}

void large_num_input(large_num_ptr num)
{
  for (int i = 0; i < num->len; i++)
  {
    num->num[i] = '0';
  }
  int cnt = 0;
  while ((num->num[cnt++] = getchar()) != '\n');
  cnt -= 2;
  //把输入内容移动到结尾
  int delta = num->len - cnt - 1;
  for (int i = num->len - 1; i >= 0 && cnt >= 0; i--)
  {
    num->num[i] = num->num[cnt--];
  }
  for (int i = 0; i < delta; i++)
  {
    num->num[i] = '0';
  }
}