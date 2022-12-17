#include <stdio.h>

double power(double x, int n)
{
	double p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= x;
	}
	return p;
}

int main()
{
	double a;
	int b;
	printf("Enter a number: \n");
	scanf("%lf", &a);
	printf("Enter a power: \n");
	scanf("%d", &b);
	printf("Result: %lf\n", power(a, b));
	return 0;
}