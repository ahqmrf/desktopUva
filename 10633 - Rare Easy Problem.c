#include <stdio.h>

void Swap(unsigned long long int &x, unsigned long long int &y)
{
	unsigned long long int t = x;
	x = y;
	y = t;
}

int main()
{
	unsigned long long int n;
	while(scanf("%llu", &n)== 1 && n)
	{
		unsigned long long int x = (10*n)/9, y = 0;
		if((x+1) - (x+1)/10 == n) y = (x+1);
		else if((x-1) - (x-1)/10 == n) y = (x-1);
		if(x > y && y) Swap(x, y);

		if(y == 0) printf("%llu\n", x);
		else printf("%llu %llu\n", x, y);
	}
	return 0;
}