//编写一个函数，输入一个整数和一个小数，四舍五入保留指定位数的小数，返回一个double
#include <stdio.h>
#include <math.h>

double lim(double num, int n)
{
	double temp = 0;
    temp = num * pow(10, n+1);
	if ((int)temp%10 >= 5)
	{
		temp += 10;
	}
    double ret = (int)temp / pow(10, n+1);
    return ret;
}

int main()
{
    double num = 0;
    int n = 0;
    scanf("%lf%d", &num, &n);
	//输出num的小数点后n位
	int ret = (int)(lim(num, n)* pow(10, n));
	int cnt = 0;
	int str[64] = {0};
	while (ret > 0){
		str[cnt] = ret % 10;
		ret /= 10;
		cnt++;
	}
	for (int i = cnt-1; i >= n; i--)
	{
		printf("%d", str[i]);
	}
	printf(".");
	for (int i = n-1; i >= 0; i--)
	{
		printf("%d",str[i]);
	}
	printf("\n");
    return 0;
}