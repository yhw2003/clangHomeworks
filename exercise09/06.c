//停车场收费系统

#include <stdio.h>

int main()
{
  int time_h,time_m;
  scanf("%dh%dm", &time_h, &time_m);
  int total_time = time_h * 60 + time_m;
  if (total_time <= 15)
  {
    printf("%d", total_time * 8);
    return 0;
  }
  if (15 < total_time && total_time <= 60)
  {
    printf("%d", 8);
    return 0;
  }
  
  int total_fee = 8 + ((total_time - 15) * 4)/30;
  if (total_fee >= 80)
  {
    printf("%d", 80);
    return 0;
  }
  printf("%d", total_fee);
  return 0;
}