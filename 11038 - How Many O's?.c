#include <stdio.h>
#include <math.h>

int no_of_digit(long long int n)
{
	int nod = 1;
	while(n > 9)
	{
		nod++;
		n /= 10;
	}
	return nod;
}

long long int no_of_zero(long long int n)
{
	long long int noz = 0;
	return noz;
}

int main()
{
	long long int n;
	while(scanf("%lld", &n) == 1)
		printf("%lld\n", no_of_zero(n));
	return 0;
}