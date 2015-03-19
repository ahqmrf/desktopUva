#include <stdio.h>

int f(int n)
{
	if(n == 0) return 0;
	if(n%10) return n%10;
	return f(n/10);
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", f(n));
	}
	return 0;
}