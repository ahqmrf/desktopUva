#include <stdio.h>
#include <math.h>
#define MOD 1000000
int ret[1000001];
int main()
{
	ret[0] = 1;
	double x;
	int i;
	for(i = 1; i <= MOD; i++)
	{
		x = i;
		ret[i] = (ret[(int)(x - sqrt(x))]%MOD + ret[(int)(log(x))]%MOD + ret[(int)(x * sin(x)*sin(x))]%MOD) % MOD;
	}
	int n;
	while(scanf("%d", &n) == 1 && n != -1)
	{
		printf("%d\n", ret[n]);
	}
	return 0;
}