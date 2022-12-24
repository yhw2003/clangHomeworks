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

extern void large_num_minus(const large_num *const numA, const large_num *const numB, large_num_ptr *result);

extern void large_num_print(const large_num *const num);

extern void large_num_input(large_num_ptr num);

int main()
{
  large_num_ptr numA = create_large_num(10), numB = create_large_num(10), result = create_large_num(10);
  large_num_input(numA);
  large_num_input(numB);
  large_num_add(numA, numB, &result);
  large_num_print(result);
  return 0;
}


large_num_ptr create_large_num(int len)
{
  large_num_ptr p = (large_num_ptr) malloc(sizeof(large_num));
  p->num = (char *) malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++)
    p->num[i] = 0;
  p->len = len;
  return p;
}

//两个家数numA和numB相加，结果存放在result中，注意提前分配好result的空间或将result初始化为NULL
void large_num_add(const large_num *const numA, const large_num *const numB, large_num_ptr *result)
{
  free(*result);
  int max_len = numA->len > numB->len ? numA->len : numB->len;
  int min_len = numA->len < numB->len ? numA->len : numB->len;
  *result = create_large_num(max_len);
  int buffer = 0;
  int i;
  for (i = 0; i < min_len; i++)
  {
    buffer = numA->num[numA->len - i - 1] - '0' + numB->num[numB->len - i - 1] - '0' + buffer;
    (*result)->num[max_len - i - 1] = buffer % 10 + '0';
    buffer /= 10;
  }
  i++;
  (*result)->num[max_len - i - 1] = buffer;
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
void large_num_minus(const large_num *const numA, const large_num *const numB, large_num_ptr *result)
{
  free(*result);
  int max_len = numA->len > numB->len ? numA->len : numB->len;
  int min_len = numA->len < numB->len ? numA->len : numB->len;
  *result = create_large_num(max_len);
  for (int i = 0; i < max_len; i++)
  {
  
  }
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
  while ((num->num[cnt++] = getchar()) != '\n')
  {
    if (cnt >= num->len)
    {
      printf("The num you input is too long!\n");
      exit(1);
    }
  }
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