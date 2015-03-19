#include <stdio.h>
int main()
{
	int coins[] =  {9261, 8000, 6859, 5832, 4913, 4096, 3375, 2744, 2197, 1728, 1331, 1000, 729, 512, 343, 216, 125, 64, 27, 8, 1};
	long long int w[10011] = {};
	w[0] = 1;
	int i, j;
	for(i = 0; i < 21; i++)
	{
		for(j = coins[i]; j < 10010; j++)
		{
			w[j] += w[j-coins[i]];
		}
	}

	int amount;
	while(scanf("%d", &amount) == 1)
	{
		printf("%lld\n", w[amount]);
	}
	return 0;
}