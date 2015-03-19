#include <stdio.h>
int main()
{
	int cases, i;
	long long f[41];
	f[0] = 0;
	f[1] = 1;
	f[2] = 5;
	f[3] = 11;
	for(i = 4; i < 41; i++)
		f[i] = f[i-1] + 4*f[i-2] + 2*f[i-3];
	long long n;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%lld", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}