#include <stdio.h>


extern int C(int n, int m);
extern int N(int n);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d", C(n,m));
}

int N(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
	return result;
}

//求C(n,m)的值
int C(int n, int m)
{
    if (m == 0 || m == n)
        return 1;
    else
        return N(n)/(N(n-m)*N(m));
}